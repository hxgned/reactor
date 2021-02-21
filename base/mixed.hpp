#ifndef XAIR_KIT_HPP
#define XAIR_KIT_HPP

#include <fcntl.h>
#include <functional>
#include <string>
#include <unistd.h>
#include <vector>

#define UNUSED(expr)                                                                               \
    do                                                                                             \
    {                                                                                              \
        (void)expr;                                                                                \
    } while (0)

namespace reactor
{
void replace_all(std::string &str, std::string from, std::string to);
// time
std::string fmt_timestamp(time_t t);
time_t      reverse_fmt_timestamp(const char *tstring);
// io
size_t                   calc_file_size(const char *path);
std::vector<std::string> get_file_names(const char *dir_path);
int                      read_file(const char *path, std::string &str);
void                     recursion_create_dir(const char *path);

bool        retry_n_times(size_t n, std::function<bool()> func, const char *error_message);
std::string Basename(std::string);
} // namespace reactor

#endif