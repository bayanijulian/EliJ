START /B /WAIT msys64\usr\bin\env MSYSTEM=MINGW64 msys64\usr\bin\bash -l -c "cd ../../../.. & echo %cd% && clang Building/x86_64-msys2-64/Tests/x86_64-msys2-64_Affirm.c -o Building/x86_64-msys2-64/Tests/x86_64-msys2-64_Affirm.exe"
START /B /WAIT msys64\usr\bin\env MSYSTEM=MINGW64 msys64\usr\bin\bash -l -c "cd ../../../.. & clang++ Building/x86_64-msys2-64/Tests/x86_64-msys2-64_Affirm-CPP.cpp -o Building/x86_64-msys2-64/Tests/x86_64-msys2-64_Affirm-CPP.exe"