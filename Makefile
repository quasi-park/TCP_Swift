SUFFIX        = .c
SWIFT_SUFFIX  = .swift
HEADER_SUFFIX = .h
CC            = clang
SWIFTCC       = swiftc
CFLAGS        = -c
SWIFTFLAGS    = -import-objc-header
SRC_DIR       = src
TGT_DIR       = bin
OBJ_DIR       = obj
C_SOURCES     = $(wildcard $(SRC_DIR)/*$(SUFFIX))
SWIFT_SOURCES = $(wildcard $(SRC_DIR)/*$(SWIFT_SUFFIX))
SWIFT_TARGET  = $(notdir $(basename $(SWIFT_SOURCES)))
C_OBJECTS     = $(notdir $(C_SOURCES:$(SUFFIX)=.o))
C_HEADERS     = $(wildcard $(SRC_DIR)/*$(HEADER_SUFFIX))
# C_TARGET = $(notdir $(basename $(C_SOURCES)))

all: $(SWIFT_TARGET)

$(SWIFT_TARGET): $(C_OBJECTS)
	@if [! -d $(TGT_DIR)]; then\
		echo "Directory $(TGT_DIR) does not exist. Creating...";\
		mkdir -p $(TGT_DIR);\
		fi
	$(SWIFTCC) $(SRC_DIR)/$@$(SWIFT_SUFFIX) $(addprefix $(OBJ_DIR)/, $(C_OBJECTS)) $(SWIFTFLAGS) "$(C_HEADERS)"

$(C_OBJECTS): $(C_SOURCES)
	@if [ ! -d $(OBJ_DIR) ]; then \
		echo "Directory $(OBJ_DIR) does not exist. Creating...";\
		mkdir -p $(OBJ_DIR);\
		fi
	$(CC) $(CFLAGS) $(SRC_DIR)/$(basename $@)$(SUFFIX) -o $(OBJ_DIR)/$@

clean:
	$(RM) -r $(TGT_DIR)/* $(OBJ_DIR)/*
