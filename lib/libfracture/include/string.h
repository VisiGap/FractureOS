#ifndef FRACTURE_STRING_H
#define FRACTURE_STRING_H

#include <cstddef>
#include <cstdint>

namespace fracture {

class String {
public:
    String() : data_(nullptr), size_(0), capacity_(0) {}
    
    explicit String(const char* str) {
        size_ = strlen(str);
        capacity_ = size_ + 1;
        data_ = new char[capacity_];
        memcpy(data_, str, size_ + 1);
    }
    
    ~String() {
        delete[] data_;
    }
    
    String(const String& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new char[capacity_];
        memcpy(data_, other.data_, size_ + 1);
    }
    
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new char[capacity_];
            memcpy(data_, other.data_, size_ + 1);
        }
        return *this;
    }
    
    const char* c_str() const { return data_; }
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    
private:
    char* data_;
    size_t size_;
    size_t capacity_;
    
    static size_t strlen(const char* str) {
        size_t len = 0;
        while (str[len]) ++len;
        return len;
    }
    
    static void memcpy(void* dest, const void* src, size_t n) {
        auto* d = static_cast<char*>(dest);
        auto* s = static_cast<const char*>(src);
        for (size_t i = 0; i < n; ++i) {
            d[i] = s[i];
        }
    }
};

} // namespace fracture

#endif // FRACTURE_STRING_H
