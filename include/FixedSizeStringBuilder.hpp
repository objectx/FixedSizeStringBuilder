/*
 * FixedSizeStringBuilder.hpp:
 *
 * Copyright 2012-2015 Masashi Fujita <objectxtreme@gmail.com>
 *
 * License: Ms-PL (http://www.opensource.org/licenses/ms-pl.html)
 */
#pragma once

#ifndef	fixedsizestringbuilder_hpp_75796D93_593C_4AC6_A9E6_0430388DB301
#define	fixedsizestringbuilder_hpp_75796D93_593C_4AC6_A9E6_0430388DB301

#include <sys/types.h>
#include <cassert>
#include <cstdarg>
#include <cstdint>
#include <cstring>

/**
 * Constructs a string into fixed sized buffer.
 *
 * @remarks This class does not own the buffer.
 */
class FixedSizeStringBuilder {
private:
    int8_t *	buffer_;
    int32_t	limit_;
    int32_t	length_;
private:
    /**
     * Disables copying.
     */
    FixedSizeStringBuilder ()
       : buffer_ (0), limit_ (0), length_ (0) {
	/* NO-OP */
    }
    /**
     * Disables copying.
     */
    FixedSizeStringBuilder &	operator = (const FixedSizeStringBuilder &) {
        return *this ;
    }
public:
    ~FixedSizeStringBuilder () {
	/* NO-OP */
    }
    FixedSizeStringBuilder (void * buffer, size_t size) {
	Attach (buffer, size);
    }
    /**
     * Attach a buffer.
     *
     * @param buffer buffer to store the result.
     * @param size the buffer size.
     *
     * @return *this (for chaining).
     */
    FixedSizeStringBuilder & Attach (void * buffer, size_t size) {
	assert (buffer != 0);
	assert (0 < size);
	buffer_ = static_cast<int8_t *> (buffer);
	limit_ = size - 1;	// -1 for proofing \0 termination.
	length_ = 0;
	buffer_ [0] = 0;
	return (*this);
    }
    /**
     * Retrieves a constructed string.
     *
     * @return constructed string
     */
    const char * GetValue () const {
	return (reinterpret_cast<const char *> (buffer_));
    }
    /**
     * Retrieves constructed string length.
     *
     * @return constructed string length
     */
    size_t	GetLength () const {
	return static_cast<size_t> (length_);
    }
    /**
     * Clear the constructed string.
     *
     * @return *this
     */
    FixedSizeStringBuilder & Clear () {
	length_ = 0;
	buffer_ [0] = 0;
	return (*this);
    }
    /**
     * Append a character.
     *
     * @param ch Character to append
     *
     * @return *this (for chaining).
     */
    FixedSizeStringBuilder &	Append (char ch);
    /**
     * Append a \0 terminated string.
     *
     * @param s String to append
     *
     * @return *this (for chaining).
     */
    FixedSizeStringBuilder &	Append (const char * s);
    /**
     * Append a LENGTH byte characters from S.
     *
     * @param s Source
     * @param length # of bytes to add.
     *
     * @return *this (for chaining).
     *
     * @remarks s [0..length] must not contain \0.
     */
    FixedSizeStringBuilder &	Append (const void * s, size_t length);
    /**
     * Append with formatting.
     *
     * @param format The format string
     * @param ap Arguments
     *
     * @return *this (for chaining)
     */
    FixedSizeStringBuilder &	AppendWithFormatV (const char *format, va_list ap);
    /**
     * Append with formatting.
     *
     * @param format The format string
     *
     * @return *this (for chaining)
     */
    FixedSizeStringBuilder &	AppendWithFormat (const char *format, ...);

    /* Operators */
    operator const char * () const {
	return GetValue () ;
    }
} ;

#endif  /* fixedsizestringbuilder_hpp_75796D93_593C_4AC6_A9E6_0430388DB301 */
/*
 * [END OF FILE]
 */
