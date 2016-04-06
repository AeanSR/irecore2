call pack_release.bat
copy "%VS140COMNTOOLS%..\..\VC\redist\x86\Microsoft.VC140.CRT"\vcruntime140.dll release\vcruntime140.dll
copy "%VS140COMNTOOLS%..\..\VC\redist\x86\Microsoft.VC140.CRT"\msvcp140.dll release\msvcp140.dll
