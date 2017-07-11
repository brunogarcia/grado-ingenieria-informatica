##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Discounts
ConfigurationName      :=Debug
WorkspacePath          :=/home/bruno/Documentos/PEC3
ProjectPath            :=/home/bruno/Documentos/PEC3/Discounts
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Bruno
Date                   :=01/05/17
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
ObjectsFileList        :="Discounts.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./includes 
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
Objects0=$(IntermediateDirectory)/source_discount.c$(ObjectSuffix) $(IntermediateDirectory)/source_main.c$(ObjectSuffix) $(IntermediateDirectory)/source_tests.c$(ObjectSuffix) 



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
$(IntermediateDirectory)/source_discount.c$(ObjectSuffix): source/discount.c $(IntermediateDirectory)/source_discount.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/Documentos/PEC3/Discounts/source/discount.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_discount.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_discount.c$(DependSuffix): source/discount.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_discount.c$(ObjectSuffix) -MF$(IntermediateDirectory)/source_discount.c$(DependSuffix) -MM source/discount.c

$(IntermediateDirectory)/source_discount.c$(PreprocessSuffix): source/discount.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_discount.c$(PreprocessSuffix) source/discount.c

$(IntermediateDirectory)/source_main.c$(ObjectSuffix): source/main.c $(IntermediateDirectory)/source_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/Documentos/PEC3/Discounts/source/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_main.c$(DependSuffix): source/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/source_main.c$(DependSuffix) -MM source/main.c

$(IntermediateDirectory)/source_main.c$(PreprocessSuffix): source/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_main.c$(PreprocessSuffix) source/main.c

$(IntermediateDirectory)/source_tests.c$(ObjectSuffix): source/tests.c $(IntermediateDirectory)/source_tests.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/bruno/Documentos/PEC3/Discounts/source/tests.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/source_tests.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/source_tests.c$(DependSuffix): source/tests.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/source_tests.c$(ObjectSuffix) -MF$(IntermediateDirectory)/source_tests.c$(DependSuffix) -MM source/tests.c

$(IntermediateDirectory)/source_tests.c$(PreprocessSuffix): source/tests.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/source_tests.c$(PreprocessSuffix) source/tests.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


