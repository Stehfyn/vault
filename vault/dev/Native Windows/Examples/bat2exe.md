# bat2exe

`bat2exe` packages a batch script into an executable wrapper, usually by embedding the script as a resource or payload and launching it through the command interpreter at runtime. The useful Native Windows angle is the resource/extraction/process-creation pipeline, not the illusion that a batch file has become native code.

Connect this to `Embedding and Extracting DLLs as Resources`, installer/bootstrapper notes, and OpSec process-spawn telemetry. Wrappers like this change distribution ergonomics and metadata, but the underlying script execution model and command-line artifacts still matter.

## References
- <https://github.com/islamadel/bat2exe>
