#!/usr/bin/python3
"""
Write a method that determines if a given data set represents a valid UTF-8
encoding.
"""


def validUTF8(data):
    """Validates that `data` is valid UTF-8."""
    continuation_bytes = 0
    for byte in data:
        check_bit = 0x80
        if byte & check_bit:
            # This is a multi-byte character
            check_bit >>= 1
            if continuation_bytes == 0:
                # A new character is expected
                # Count continuation bytes
                while check_bit & byte:
                    if continuation_bytes > 3:
                        # Too many continuation bytes
                        return False
                    continuation_bytes += 1
                    check_bit >>= 1
                # Byte might be overlong; Count the free bits
                free_bits = 8 - (continuation_bytes + 2)
                if continuation_bytes == 0:
                    # An unexpected continuation byte was encountered
                    return False
            else:
                # A continuation byte is expected
                if (byte & 0x3F).bit_length() >= free_bits:
                    # Overlong encoding encountered
                    return False
                if check_bit & byte:
                    # A non-continuation byte was encountered
                    return False
                # A valid continuation byte was found
                continuation_bytes -= 1
        else:
            # This is a single-byte (ASCII) character
            if continuation_bytes:
                # A continuation byte was expected
                return False
    if continuation_bytes:
        # Bytes ended mid-character
        return False
    return True
