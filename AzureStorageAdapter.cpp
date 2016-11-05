#include "AzureStorageAdapter.h"

 
char_array_buffer::char_array_buffer(char *data, unsigned int len)
: begin_(data), end_(data + len), current_(data) { }
 
char_array_buffer::int_type char_array_buffer::underflow() {
    if (current_ == end_) {
        return traits_type::eof();
    }
    return traits_type::to_int_type(*current_);     // HERE!
}
 
char_array_buffer::int_type char_array_buffer::uflow() {
    if (current_ == end_) {
        return traits_type::eof();
    }
    return traits_type::to_int_type(*current_++);   // HERE!
}
 
char_array_buffer::int_type char_array_buffer::pbackfail(int_type ch) {
    if (current_ == begin_ || (ch != traits_type::eof() && ch != current_[-1])) {
        return traits_type::eof();
    }
    return traits_type::to_int_type(*--current_);   // HERE!
}
 
std::streamsize char_array_buffer::showmanyc() {
    return end_ - current_;
}