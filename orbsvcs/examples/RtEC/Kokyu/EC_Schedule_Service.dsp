# Microsoft Developer Studio Project File - Name="EC_Schedule_Service" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=EC_Schedule_Service - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "EC_Schedule_Service.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "EC_Schedule_Service.mak" CFG="EC_Schedule_Service - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "EC_Schedule_Service - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "EC_Schedule_Service - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "EC_Schedule_Service - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release\EC_Schedule_Service"
# PROP BASE Intermediate_Dir "Release\EC_Schedule_Service"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\EC_Schedule_Service"
# PROP Intermediate_Dir "Release\EC_Schedule_Service"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE CPP /nologo /W3 /GX /D "WIN32" /D "_WINDOWS" /D "_CONSOLE" /D "_MBCS" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../../" /I "../../../../" /I "../../../" /D "WIN32" /D "_WINDOWS" /D "_CONSOLE" /D "_MBCS" /D "NDEBUG" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 ace.lib tao.lib TAO_PortableServer.lib TAO_Messaging.lib TAO_CosNaming.lib TAO_RTEvent.lib TAO_RTSched.lib TAO_RTKokyuEvent.lib TAO_Svc_Utils.lib /nologo /subsystem:console /machine:I386 /out:"Service.exe" /libpath:"../../../../../ace" /libpath:"../../../../tao" /libpath:"../../../../tao/PortableServer" /libpath:"../../../../tao/Messaging" /libpath:"../../../orbsvcs"

!ELSEIF  "$(CFG)" == "EC_Schedule_Service - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir "Debug\EC_Schedule_Service"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug\EC_Schedule_Service"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /D "WIN32" /D "_WINDOWS" /D "_CONSOLE" /D "_MBCS" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../../../../../" /I "../../../../" /I "../../../" /D "WIN32" /D "_WINDOWS" /D "_CONSOLE" /D "_MBCS" /D "_DEBUG" /FD /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 aced.lib taod.lib TAO_PortableServerd.lib TAO_Messagingd.lib TAO_CosNamingd.lib TAO_RTEventd.lib TAO_RTSchedd.lib TAO_RTKokyuEventd.lib TAO_Svc_Utilsd.lib /nologo /subsystem:console /debug /machine:I386 /out:"Service.exe" /pdbtype:sept /libpath:"../../../../../ace" /libpath:"../../../../tao" /libpath:"../../../../tao/PortableServer" /libpath:"../../../../tao/Messaging" /libpath:"../../../orbsvcs"

!ENDIF 

# Begin Target

# Name "EC_Schedule_Service - Win32 Release"
# Name "EC_Schedule_Service - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Consumer.cpp
# End Source File
# Begin Source File

SOURCE=.\Service.cpp
# End Source File
# Begin Source File

SOURCE=.\Supplier.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;fi;fd"
# Begin Source File

SOURCE=.\Consumer.h
# End Source File
# Begin Source File

SOURCE=.\Supplier.h
# End Source File
# End Group
# Begin Group "IDL Files"

# PROP Default_Filter "idl;pidl"
# End Group
# Begin Group "Inline Files"

# PROP Default_Filter "inl;i"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
