@echo off
SET HEADER_PATH=%SCE_PSP2_SDK_DIR%\target\include\vdsuite\user

@RD /S /Q include

robocopy "%HEADER_PATH%\paf" include\paf /COPYALL /E

copy "%HEADER_PATH%\app_settings.h" include
copy "%HEADER_PATH%\common_gui_dialog.h" include
copy "%HEADER_PATH%\paf.h" include
copy "%HEADER_PATH%\paf_web_map_view.h" include
copy "%HEADER_PATH%\paf_web_ui.h" include