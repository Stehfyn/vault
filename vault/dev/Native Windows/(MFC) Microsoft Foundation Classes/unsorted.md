https://github.com/jwhu1024/MFC
https://www.codeproject.com/Articles/611/Zip-and-Unzip-in-the-MFC-way
https://files.cbps.xyz/archive/ipw/exe/source/
@QuixTest#9498 that makes me feel better lol thanks for letting me know! I'll stay on the hunt despite what looks to be a fun ride into the unknown of MFC land. For anyone stumbling looks like the vs .sln references a missing zip utility project that iPodWizard is dependent on,
```
EndProject
Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "Zip", "..\zip\Zip.vcproj", "{342C6CC5-06F0-4A06-83CD-C52E210E1B6D}"
EndProject
```
99% sure that operates on the Zip.lib, and builds something to link against. Also 99.99% sure i found it as certain ipw includes match the vc++ .dsw and .dsp  from https://www.codeproject.com/Articles/611/Zip-and-Unzip-in-the-MFC-way ```//iPodWizardDlg.h
#include "..\Zip\ZipArchive.h"

//zip_src.zip
ZipArchive.dsw
ZipArchive.dsp```
Lastly I found a typelib header at https://files.cbps.xyz/archive/ipw/exe/source/ with 2021 generation date?!?!
So overall thinking then just figuring out dependency linkage and build environment gives a stable build
