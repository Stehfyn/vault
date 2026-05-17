# Duff's Device

Duff's device unrolls a loop using C's switch fallthrough. It copies n bytes 8 at a time with a partial first iteration. While compilers now auto-unroll better, it remains a famous example of interleaving switch and loop structure — valid C since the standard explicitly permits this.

```cpp
// Classic Duff's Device - copies `count` bytes from `from` to `to`
// n = ceil(count/8), switch handles the remainder on the first pass
int DuffCopy(char* to, const char* from, int count) {
    if (count <= 0) return 0;
    int n = (count + 7) / 8;
    switch (count % 8) {
        case 0: do { *to++ = *from++;
        case 7:      *to++ = *from++;
        case 6:      *to++ = *from++;
        case 5:      *to++ = *from++;
        case 4:      *to++ = *from++;
        case 3:      *to++ = *from++;
        case 2:      *to++ = *from++;
        case 1:      *to++ = *from++;
                } while (--n > 0);
    }
    return count;
}

// Modern equivalent - compiler unrolls this just as well:
// memcpy(to, from, count);  // use this in practice
```

The significance: demonstrates that C's grammar allows arbitrary interleaving of switch labels and loop bodies. The do-while loop spans across the switch cases.

## References
- https://en.wikipedia.org/wiki/Duff%27s_device
