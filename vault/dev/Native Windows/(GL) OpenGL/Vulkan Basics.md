# Vulkan Initialization

Vulkan requires explicit setup of instance, physical device, logical device, and swap chain. Unlike OpenGL, there is no implicit context; every object is explicitly created and destroyed. Use validation layers (`VK_LAYER_KHRONOS_validation`) during development.

```cpp
// Minimal Vulkan instance creation
VkApplicationInfo appInfo = {};
appInfo.sType            = VK_STRUCTURE_TYPE_APPLICATION_INFO;
appInfo.pApplicationName = "Demo";
appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.apiVersion       = VK_API_VERSION_1_2;

const char* layers[] = { "VK_LAYER_KHRONOS_validation" };
VkInstanceCreateInfo ci = {};
ci.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
ci.pApplicationInfo        = &appInfo;
ci.enabledLayerCount        = 1;
ci.ppEnabledLayerNames      = layers;

VkInstance instance = VK_NULL_HANDLE;
vkCreateInstance(&ci, nullptr, &instance);

// Enumerate physical devices
uint32_t devCount = 0;
vkEnumeratePhysicalDevices(instance, &devCount, nullptr);
std::vector<VkPhysicalDevice> devices(devCount);
vkEnumeratePhysicalDevices(instance, &devCount, devices.data());
VkPhysicalDeviceProperties props = {};
vkGetPhysicalDeviceProperties(devices[0], &props);
```

## References
- https://www.howtovulkan.com/
