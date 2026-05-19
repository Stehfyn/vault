<!-- generated-from-dump2 -->
# Vulkan Hello Triangle (Single-File Reference)

Single-file, heavily-commented Vulkan "hello triangle" — the canonical reference for *every* call you have to make to get a triangle on screen with no abstraction layer hiding the noise. Useful when you want to see all ~30 of the things `vkCreateXxx` you skipped in a tutorial because a helper macro wrapped them.

```cpp
VkInstanceCreateInfo ici{VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
VkInstance inst; vkCreateInstance(&ici, nullptr, &inst);

uint32_t n = 0; vkEnumeratePhysicalDevices(inst, &n, nullptr);
std::vector<VkPhysicalDevice> phys(n); vkEnumeratePhysicalDevices(inst, &n, phys.data());

float q = 1.0f;
VkDeviceQueueCreateInfo qci{VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
    nullptr, 0, /*familyIndex*/ 0, 1, &q};
VkDeviceCreateInfo dci{VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO};
dci.queueCreateInfoCount = 1; dci.pQueueCreateInfos = &qci;
VkDevice dev; vkCreateDevice(phys[0], &dci, nullptr, &dev);
```

## References
- <https://github.com/krOoze/Hello_Triangle>
