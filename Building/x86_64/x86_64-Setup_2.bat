ECHO "Run MSYS2 for Package Updating"
START /WAIT msys64\usr\bin\bash -l -c "Pacman -Syu && exit"

EXIT 0