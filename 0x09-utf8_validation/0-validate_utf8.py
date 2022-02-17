#!/usr/bin/python3
"""
Write a method that determines if a given data set represents a valid UTF-8
encoding.
"""


def validUTF8(data):
    """Validates that `data` is valid UTF-8."""
    continuation_bytes = 0
    start_multibyte = False
    for byte in data:
        check_bit = 0x80
        if byte & check_bit:
            # This is a multi-byte character
            check_bit >>= 1
            if continuation_bytes == 0:
                # A new character is expected
                # Count continuation bytes
                while check_bit & byte:
                    start_multibyte = True
                    continuation_bytes += 1
                    check_bit >>= 1
                    if continuation_bytes > 3:
                        # Too many continuation bytes
                        return False
                # Byte might be overlong; Count the free bits
                free_bits = 6 - continuation_bytes
                if (check_bit - 1) & byte:
                    free_bits = 0
                if continuation_bytes == 0:
                    # An unexpected continuation byte was encountered
                    return False
            else:
                # A continuation byte is expected
                if start_multibyte and (byte & 0x3F).bit_length() <= free_bits:
                    # Overlong encoding encountered
                    return False
                start_multibyte = False
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
