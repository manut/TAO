# Microsoft Developer Studio Project File - Name="RateGen_svnt DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RateGen_svnt DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RateGen_svnt.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RateGen_svnt.mak" CFG="RateGen_svnt DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RateGen_svnt DLL - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RateGen_svnt DLL - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RateGen_svnt DLL - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "Release\RateGen_svnt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GR /GX /Zi /O2 /I "..\..\..\..\..\orbsvcs\orbsvcs" /I "..\..\..\.." /I "..\..\..\..\ciao" /I "..\..\..\..\.." /I "..\..\..\..\..\tao" /I "..\..\..\..\..\.." /D NDEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D RATEGEN_SVNT_BUILD_DLL=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\.." /i "..\..\..\..\ciao" /i "..\..\..\..\.." /i "..\..\..\..\..\tao" /i "..\..\..\..\..\.." /d NDEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib RateGen_stub.lib HUDisplay_stub.lib HUDisplay_svnt.lib CIAO_Server.lib TAO_PortableServer.lib TAO_IORInterceptor.lib TAO_ObjRefTemplate.lib TAO_Security.lib CIAO_Container.lib TAO.lib TAO_IFR_Client.lib TAO_Valuetype.lib CIAO_Client.lib ACE.lib /nologo /subsystem:windows /dll /pdb:"..\..\..\..\..\..\bin\RateGen_svnt.pdb" /machine:I386 /out:"..\..\..\..\..\..\bin\RateGen_svnt.dll" /libpath:".." /libpath:"..\..\..\..\..\tao\PortableServer" /libpath:"..\..\..\..\..\tao\IORInterceptor" /libpath:"..\..\..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\..\tao\IFR_Client" /libpath:"..\..\..\..\..\tao\Valuetype" /libpath:"..\..\..\..\ciao" /libpath:"..\..\..\..\..\tao" /libpath:"..\..\..\..\..\..\ace" /version:1.3.1
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "RateGen_svnt DLL - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug\RateGen_svnt"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /Gy /I "..\..\..\..\..\orbsvcs\orbsvcs" /I "..\..\..\.." /I "..\..\..\..\ciao" /I "..\..\..\..\.." /I "..\..\..\..\..\tao" /I "..\..\..\..\..\.." /D _DEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D RATEGEN_SVNT_BUILD_DLL=1 /FD /c
# SUBTRACT CPP /Fr /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "..\..\..\..\..\orbsvcs\orbsvcs" /i "..\..\..\.." /i "..\..\..\..\ciao" /i "..\..\..\..\.." /i "..\..\..\..\..\tao" /i "..\..\..\..\..\.." /d _DEBUG=1
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib RateGen_stubd.lib HUDisplay_stubd.lib HUDisplay_svntd.lib CIAO_Serverd.lib TAO_PortableServerd.lib TAO_IORInterceptord.lib TAO_ObjRefTemplated.lib TAO_Securityd.lib CIAO_Containerd.lib TAOd.lib TAO_IFR_Clientd.lib TAO_Valuetyped.lib CIAO_Clientd.lib ACEd.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"..\..\..\..\..\..\bin\RateGen_svntd.pdb" /debug /machine:I386 /out:"..\..\..\..\..\..\bin\RateGen_svntd.dll" /libpath:".." /libpath:"..\..\..\..\..\tao\PortableServer" /libpath:"..\..\..\..\..\tao\IORInterceptor" /libpath:"..\..\..\..\..\tao\ObjRefTemplate" /libpath:"..\..\..\..\..\orbsvcs\orbsvcs" /libpath:"..\..\..\..\..\tao\IFR_Client" /libpath:"..\..\..\..\..\tao\Valuetype" /libpath:"..\..\..\..\ciao" /libpath:"..\..\..\..\..\tao" /libpath:"..\..\..\..\..\..\ace" /version:1.3.1
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "RateGen_svnt DLL - Win32 Release"
# Name "RateGen_svnt DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=.\RateGen_svnt.cpp
# End Source File
# Begin Source File

SOURCE=.\RateGenEC.cpp
# End Source File
# Begin Source File

SOURCE=.\RateGenS.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=.\RateGen_svnt.h
# End Source File
# Begin Source File

SOURCE=.\RateGenEC.h
# End Source File
# Begin Source File

SOURCE=.\RateGenS.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "i;inl"
# Begin Source File

SOURCE=.\RateGenEC.i
# End Source File
# Begin Source File

SOURCE=.\RateGenS.i
# End Source File
# End Group
# Begin Group "IDL Files"

# PROP Default_Filter "idl"
# Begin Source File

SOURCE=.\RateGen.cidl

!IF  "$(CFG)" == "RateGen_svnt DLL - Win32 Release"

!ELSEIF  "$(CFG)" == "RateGen_svnt DLL - Win32 Debug"

USERDEP__RATEG="..\..\..\..\..\..\bin\cidlc.exe"	
# Begin Custom Build - Invoking CIAO CIDL Compiler on $(InputPath)
InputPath=.\RateGen.cidl
InputName=RateGen

BuildCmds= \
	..\..\..\..\bin\cidlc --lem-file-suffix "E.idl" -- $(InputName).cidl

"$(InputName)E.idl" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName)_svnt.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputName)_svnt.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\RateGenE.idl

!IF  "$(CFG)" == "RateGen_svnt DLL - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\RateGenE.idl
InputName=RateGenE

BuildCmds= \
	..\..\..\..\..\..\bin\tao_idl -o . -Wb,export_macro=RATEGEN_SVNT_Export -Wb,export_include=RateGen_svnt_export.h -I..\..\..\..\.. -I..\..\..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\..\..\.. -I ..\..\..\..\.. -I ..\..\..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "RateGen_svnt DLL - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Invoking IDL Compiler on $(InputPath)
InputPath=.\RateGenE.idl
InputName=RateGenE

BuildCmds= \
	..\..\..\..\..\..\bin\tao_idl -o . -Wb,export_macro=RATEGEN_SVNT_Export -Wb,export_include=RateGen_svnt_export.h -I..\..\..\..\.. -I..\..\..\..\..\CIAO\ciao -Wb,pre_include="ace\pre.h" -Wb,post_include="ace\post.h" -I ..\..\..\.. -I ..\..\..\..\.. -I ..\..\..\..\..\orbsvcs\orbsvcs -Ge 1 -Sc $(InputPath)

".\$(InputName)C.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)C.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.i" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

".\$(InputName)S.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
