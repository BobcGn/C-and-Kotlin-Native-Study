#ifndef KOTLIN_NATIVE_STUDY_RAII_FILE_HPP
#define KOTLIN_NATIVE_STUDY_RAII_FILE_HPP

#include <cstdio>
#include <string>

class File
{
public:
    File(
        const char *path,
        const char *mode);

    ~File() noexcept;

    File(const File &) = delete;
    File &operator=(const File &) = delete;

    File(File &&) = delete;
    File &operator=(File &&) = delete;

    void write(const char *text);

    void flush();

    std::FILE *get() const noexcept;

    const std::string &path() const noexcept;

private:
    std::FILE *file_;
    std::string path_;
};

#endif // KOTLIN_NATIVE_STUDY_RAII_FILE_HPP
