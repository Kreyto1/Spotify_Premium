@echo off
echo *****************
echo Discord: Kreyto.sql
echo *****************
echo Removing Patch
if exist "%APPDATA%\Spotify\dpapi.dll" (
    del /s /q "%APPDATA%\Spotify\dpapi.dll" > NUL 2>&1
) else (
    echo done
)
pause