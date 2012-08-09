SDI External
------------

This repo contains the source code and code::blocks project for building the DLL wrapper 
which enables IDL to call routines in external DLL's (the Andor camera, the MOXA driver, 
the USB drivers). 

Note that the DLL's contained in this repo must be in the target machines path for IDL to 
be able to call the routines in them. The DLL's are:

AIOUSB.dll - USB driver 
ATMCD32D.dll - Andor EMCCD camer driver
dforrt.dll - Fortran runtime library, used by HWM for example
idl32.dll - IDL's external interface
PCOMM.dll - The MOXA usb-hub driver

To build sdi_external.dll: 
download code::blocks from http://www.codeblocks.org/downloads/26#windows, select the 
version which comes bundled with MinGW (e.g. codeblocks-10.05mingw-setup.exe). This will
install the MinGW compiler tools (basically GCC for windows), which is the compiler this
project has been tested with. Open the code::blocks project (in /build), select build
target (e.g. release), rebuild the project, and pray. If it works, the built DLL will 
be put into /build/bin/release/sdi_external.dll. Move it into the target machine's path
(same place as the other dll's) and try it out. 
