# Embedding and Extracting DLLs as Resources

Giovanni Dicanio's article is a clear reference for storing arbitrary binary payloads, including DLLs, as Win32 resources and extracting them at runtime. The useful part is the resource pipeline: `.rc` declaration, custom resource type, `FindResource`/`LoadResource`/`LockResource`, size retrieval, and the decision to materialize bytes to disk before normal loading.

This belongs near PE/resource and deployment notes, not OpSec injection material. It is legitimate for single-file helpers, installers, and plugin bootstrap code, but it also forces decisions about temp paths, signatures, update behavior, and AV heuristics.

## References
- <https://giodicanio.com/2024/03/25/embedding-and-extracting-binary-files-like-dlls-into-an-exe-as-resources>
