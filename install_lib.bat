@echo off
SET STUB_PATH=%SCE_PSP2_SDK_DIR%\target\lib\vdsuite
SET ARMLIBGEN=%SCE_PSP2_SDK_DIR%\host_tools\build\bin\armlibgen.exe
SET STUBCOUNT=14

@RD /S /Q stubs
mkdir stubs

@RD /S /Q stubs_weak
mkdir stubs_weak

pushd stubs
for %%f in (..\lib\*.emd) do (
"%ARMLIBGEN%" --dump "%%f" --stub-archive
)
popd

set fcnt=0
for %%A in (stubs\*.a) do set /a fcnt+=1

if NOT "%fcnt%"=="%STUBCOUNT%" (
  echo Some stubs were not generated correctly, aborting!
  exit /b 0
)

pushd stubs_weak
for %%f in (..\lib\*.emd) do (
"%ARMLIBGEN%" --dump "%%f" "stubs" --stub-archive --weak-stub --stub-postfix=_weak
)
popd

set fcnt=0
for %%A in (stubs_weak\*.a) do set /a fcnt+=1

if NOT "%fcnt%"=="%STUBCOUNT%" (
  echo Some stubs were not generated correctly, aborting!
  exit /b 0
)

robocopy stubs "%STUB_PATH%" /COPYALL /E
robocopy stubs_weak "%STUB_PATH%" /COPYALL /E