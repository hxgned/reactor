#include "net/Buffer.hpp"

namespace reactor
{

void Buffer::retrive(std::size_t n)
{
    if (n > windex_)
    {
        retrive_all();
    }
    else
    {
        rindex_ += n;
    }
}
void Buffer::retrive_all() { rindex_ = windex_ = 0; }

std::string_view Buffer::read(size_t n) const
{
    size_t byte = (n > readable_bytes() ? readable_bytes() : n);
    return std::string_view(buffer_.data() + rindex_, byte);
}

template <typename Tp>
void Buffer::append<Tp>(Tp *p, size_t n)
{
    make_space_for_write(n * sizeof(Tp));
    memcpy(buffer_.data() + windex_, p, n * sizeof(Tp));
}

void Buffer::append(std::string_view s) { append(s.c_str(), s.size()); }

void Buffer::swap(Buffer &rhs)
{
    rhs.buffer_.swap(buffer_);
    std::swap(rindex_, rhs.rindex_);
    std::swap(windex_, rhs.windex_);
}

void Buffer::make_space_for_write(size_t n)
{
    if (writeable_bytes() > n)
    {
        return;
    }
    else if (buffer_.size() - readable_bytes() >= n) //挪一下就能有地方
    {
        std::copy(buffer_.begin() + rindex_,
          buffer_.begin() + windex_,
          buffer_.begin());
    }
    else //申请新空间 预留两倍n
    {
        std::vector<char> tmp(readable_bytes() + 2 * n);
        std::copy(buffer_.begin() + rindex_,
          buffer_.begin() + windex_,
          tmp.begin());
        buffer_.swap(tmp);
        windex_ = readable_bytes();
        rindex_ = 0;
    }
}

} // namespace reactor