# Microsoft Developer Studio Project File - Name="RTKokyuEvent" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=RTKokyuEvent - Win32 MFC Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RTKokyuEvent.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RTKokyuEvent.mak" CFG="RTKokyuEvent - Win32 MFC Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "RTKokyuEvent - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RTKokyuEvent - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RTKokyuEvent - Win32 MFC Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "RTKokyuEvent - Win32 MFC Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "RTKokyuEvent - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "DLL\Release\RTKokyuEvent"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "RTKokyuEvent_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../" /I "../../" /I "../../../" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 TAO_Svc_Utils.lib TAO_RTSched.lib TAO_RTEvent.lib ace.lib TAO.lib TAO_PortableServer.lib Kokyu.lib /nologo /dll /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEvent.dll" /libpath:"..\..\tao\PortableServer" /libpath:"..\..\tao" /libpath:"..\..\..\ace" /libpath:"..\..\..\Kokyu"

!ELSEIF  "$(CFG)" == "RTKokyuEvent - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "DLL\Debug\RTKokyuEvent"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "RTKokyuEvent_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../" /I "../../" /I "../../../" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 TAO_Svc_Utilsd.lib TAO_RTSchedd.lib TAO_RTEventd.lib TAOd.lib aced.lib TAO_PortableServerd.lib Kokyud.lib /nologo /dll /debug /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEventd.dll" /pdbtype:sept /libpath:"..\..\tao\PortableServer" /libpath:"..\..\tao" /libpath:"..\..\..\ace" /libpath:"..\..\..\Kokyu"

!ELSEIF  "$(CFG)" == "RTKokyuEvent - Win32 MFC Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "RTKokyuEvent___Win32_MFC_Debug"
# PROP BASE Intermediate_Dir "RTKokyuEvent___Win32_MFC_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "DLL\Debug\RTKokyuEventMFC"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../" /I "../../" /I "../../../" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../" /I "../../" /I "../../../" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /D ACE_HAS_MFC=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 TAOd.lib aced.lib TAO_Svc_Utilsd.lib TAO_RTSchedd.lib TAO_RTEventd.lib /nologo /dll /debug /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEventd.dll" /pdbtype:sept /libpath:"..\..\tao" /libpath:"..\..\..\ace"
# ADD LINK32 TAOmfcd.lib acemfcd.lib TAO_Svc_Utilsmfcd.lib TAO_RTSchedmfcd.lib TAO_RTEventmfcd.lib TAO_PortableServermfcd.lib Kokyumfcd.lib /nologo /dll /debug /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEventmfcd.dll" /pdbtype:sept /libpath:"..\..\tao\PortableServer" /libpath:"..\..\tao" /libpath:"..\..\..\ace" /libpath:"..\..\..\Kokyu"

!ELSEIF  "$(CFG)" == "RTKokyuEvent - Win32 MFC Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "RTKokyuEvent___Win32_MFC_Release"
# PROP BASE Intermediate_Dir "RTKokyuEvent___Win32_MFC_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir "DLL\Release\RTKokyuEventMFC"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "../" /I "../../" /I "../../../" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../" /I "../../" /I "../../../" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "TAO_RTKOKYUEVENT_BUILD_DLL" /D ACE_HAS_MFC=1 /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ace.lib TAO.lib TAO_Svc_Utils.lib TAO_RTSched.lib TAO_RTEvent.lib /nologo /dll /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEvent.dll" /libpath:"..\..\tao" /libpath:"..\..\..\ace"
# ADD LINK32 acemfc.lib TAOmfc.lib TAO_Svc_Utilsmfc.lib TAO_RTSchedmfc.lib TAO_RTEventmfc.lib TAO_PortableServermfc.lib Kokyumfc.lib /nologo /dll /machine:I386 /out:"..\..\..\bin\TAO_RTKokyuEventmfc.dll" /libpath:"..\..\tao\PortableServer" /libpath:"..\..\tao" /libpath:"..\..\..\ace" /libpath:"..\..\..\Kokyu"

!ENDIF 

# Begin Target

# Name "RTKokyuEvent - Win32 Release"
# Name "RTKokyuEvent - Win32 Debug"
# Name "RTKokyuEvent - Win32 MFC Debug"
# Name "RTKokyuEvent - Win32 MFC Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Dispatching.cpp
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Factory.cpp
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter.cpp
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter_Builder.cpp
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Scheduling.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Dispatching.h
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Factory.h
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter.h
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter_Builder.h
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Scheduling.h
# End Source File
# Begin Source File

SOURCE=.\Event\rtkokyu_event_export.h
# End Source File
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter ".i"
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Dispatching.i
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Factory.i
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter.i
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Filter_Builder.i
# End Source File
# Begin Source File

SOURCE=.\Event\EC_Kokyu_Scheduling.i
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "rc"
# End Group
# End Target
# End Project
