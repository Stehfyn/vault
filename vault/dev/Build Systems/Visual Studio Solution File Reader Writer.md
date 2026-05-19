<!-- generated-from-dump2 -->
# Visual Studio Solution File Reader Writer

Wrong subdir — not OpSec. This is Microsoft's open-source C# library used by VS, dotnet CLI, and Rider to read/write `.sln` (old textual) and `.slnx` (new XML) Visual Studio solution files. Useful if you build dev tooling that needs to manipulate solutions without shelling out to `dotnet sln`. Should be moved to `vault/dev/Build Systems/` or `vault/dev/Languages/CSharp/`.

```csharp
using Microsoft.VisualStudio.SolutionPersistence;
using Microsoft.VisualStudio.SolutionPersistence.Serializer;

var serializer = SolutionSerializers.GetSerializerByMoniker("foo.sln");
SolutionModel sln = await serializer.OpenAsync("foo.sln", CancellationToken.None);
foreach (var proj in sln.SolutionProjects) {
    Console.WriteLine($"{proj.DisplayName} -> {proj.FilePath}");
}
await serializer.SaveAsync("foo.sln", sln, CancellationToken.None);
```

## References
- <https://github.com/microsoft/vs-solutionpersistence>
