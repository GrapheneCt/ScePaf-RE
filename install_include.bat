@echo off
SET HEADER_PATH=%SCE_PSP2_SDK_DIR%\target\include\vdsuite\user

@RD /S /Q "%HEADER_PATH%\paf"

robocopy include "%HEADER_PATH%" /COPYALL /E