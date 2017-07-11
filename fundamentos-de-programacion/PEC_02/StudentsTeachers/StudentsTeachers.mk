##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=StudentsTeachers
ConfigurationName      :=Debug
WorkspacePath          :=/home/bruno/Documentos/StudentsTeachers
ProjectPath            :=/home/bruno/Documentos/StudentsTeachers/StudentsTeachers
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Bruno
Date                   :=07/04/17
CodeLitePath           :=/home/bruno/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=./bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="StudentsTeachers.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_StudentsTeachers.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/Documentos/StudentsTeachers/StudentsTeachers/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM src/main.c

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) src/main.c

$(IntermediateDirectory)/src_StudentsTeachers.c$(ObjectSuffix): src/StudentsTeachers.c $(IntermediateDirectory)/src_StudentsTeachers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/Documentos/StudentsTeachers/StudentsTeachers/src/StudentsTeachers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_StudentsTeachers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_StudentsTeachers.c$(DependSuffix): src/StudentsTeachers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_StudentsTeachers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_StudentsTeachers.c$(DependSuffix) -MM src/StudentsTeachers.c

$(IntermediateDirectory)/src_StudentsTeachers.c$(PreprocessSuffix): src/StudentsTeachers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_StudentsTeachers.c$(PreprocessSuffix) src/StudentsTeachers.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


