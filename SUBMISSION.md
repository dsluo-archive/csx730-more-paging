# csx730-paging Submission

## Group Member Names

* David Luo 811357331 4730
* Devan Vitha 811055508 4730

## Questions

1. num_pages * page_size = 2^(M-N) * 2^N = 2^M = 2^64 = 18446744073709551616

2. num_pages = 2^(M-N) = 2^(64 - 12) = 2^52 = 4503599627370496

3. table_size = num_pages * sizeof(addr_t) = 2^52 * 8 = 36028797018963968 bytes = 33554432 gigabytes

4. table0_size = 2^((M-N)/2) * sizeof(addr_t) = 536870912 bytes = 524288 kilobytes

5. table0_size = 2^((M-N)/4) * sizeof(addr_t) = 8192 bytes = 8 kilobytes

## Struct Size

The size of `struct addr_type` is 8 bytes.
