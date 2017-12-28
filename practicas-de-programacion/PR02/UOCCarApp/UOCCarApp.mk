##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCCarApp
ConfigurationName      :=Debug
WorkspacePath          :=/home/bruno/UOC/pract02
ProjectPath            :=/home/bruno/UOC/pract02/UOCCarApp
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Bruno
Date                   :=26/11/17
CodeLitePath           :=/home/bruno/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UOCCarApp.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include $(IncludeSwitch)../UOCCarLib/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UOCCarLib 
ArLibs                 :=  "UOCCarLib" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall  -Werror $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  -Werror $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) $(IntermediateDirectory)/src_appMenu.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "../.build-debug/UOCCarLib" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"../.build-debug/UOCCarLib":
	@$(MakeDirCommand) "../.build-debug"
	@echo stam > "../.build-debug/UOCCarLib"




MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/UOC/pract02/UOCCarApp/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix): src/appMain.c $(IntermediateDirectory)/src_appMain.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/UOC/pract02/UOCCarApp/src/appMain.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_appMain.c$(DependSuffix): src/appMain.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_appMain.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_appMain.c$(DependSuffix) -MM src/appMain.c

$(IntermediateDirectory)/src_appMain.c$(PreprocessSuffix): src/appMain.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_appMain.c$(PreprocessSuffix) src/appMain.c

$(IntermediateDirectory)/src_appMenu.c$(ObjectSuffix): src/appMenu.c $(IntermediateDirectory)/src_appMenu.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/UOC/pract02/UOCCarApp/src/appMenu.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_appMenu.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_appMenu.c$(DependSuffix): src/appMenu.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_appMenu.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_appMenu.c$(DependSuffix) -MM src/appMenu.c

$(IntermediateDirectory)/src_appMenu.c$(PreprocessSuffix): src/appMenu.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_appMenu.c$(PreprocessSuffix) src/appMenu.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


