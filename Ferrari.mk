##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Ferrari
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Felipe\Documents\XboxClassP2\Xbox"
ProjectPath            := "C:\Users\Felipe\Documents\GitHub\Ferrari"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Felipe
Date                   :=10/26/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Ferrari.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Ferrari.cpp$(ObjectSuffix) $(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Multa.cpp$(ObjectSuffix) $(IntermediateDirectory)/Carro.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Ferrari.cpp$(ObjectSuffix): Ferrari.cpp $(IntermediateDirectory)/Ferrari.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/Ferrari.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ferrari.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ferrari.cpp$(DependSuffix): Ferrari.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ferrari.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Ferrari.cpp$(DependSuffix) -MM "Ferrari.cpp"

$(IntermediateDirectory)/Ferrari.cpp$(PreprocessSuffix): Ferrari.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ferrari.cpp$(PreprocessSuffix) "Ferrari.cpp"

$(IntermediateDirectory)/Data.cpp$(ObjectSuffix): Data.cpp $(IntermediateDirectory)/Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data.cpp$(DependSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Data.cpp$(DependSuffix) -MM "Data.cpp"

$(IntermediateDirectory)/Data.cpp$(PreprocessSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data.cpp$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix): Pessoa.cpp $(IntermediateDirectory)/Pessoa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/Pessoa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pessoa.cpp$(DependSuffix): Pessoa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pessoa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pessoa.cpp$(DependSuffix) -MM "Pessoa.cpp"

$(IntermediateDirectory)/Pessoa.cpp$(PreprocessSuffix): Pessoa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pessoa.cpp$(PreprocessSuffix) "Pessoa.cpp"

$(IntermediateDirectory)/Multa.cpp$(ObjectSuffix): Multa.cpp $(IntermediateDirectory)/Multa.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/Multa.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Multa.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Multa.cpp$(DependSuffix): Multa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Multa.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Multa.cpp$(DependSuffix) -MM "Multa.cpp"

$(IntermediateDirectory)/Multa.cpp$(PreprocessSuffix): Multa.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Multa.cpp$(PreprocessSuffix) "Multa.cpp"

$(IntermediateDirectory)/Carro.cpp$(ObjectSuffix): Carro.cpp $(IntermediateDirectory)/Carro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Felipe/Documents/GitHub/Ferrari/Carro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Carro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Carro.cpp$(DependSuffix): Carro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Carro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Carro.cpp$(DependSuffix) -MM "Carro.cpp"

$(IntermediateDirectory)/Carro.cpp$(PreprocessSuffix): Carro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Carro.cpp$(PreprocessSuffix) "Carro.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../XboxClassP2/Xbox/.build-debug/Ferrari"


