#
# makefile
#

# Variables Used by Implicit Rules
AR := ar rcvs
CC := gcc
CXX :=
RM := rm -rf
CFLAGS := -O1 -Iinclude
CPPFLAGS :=
LDFLAGS :=
LDLIBS :=

# Variables Used by My Rules
PROJECTNAME := schrocat
LIBRARYNAME := schrocat
OUTDIR := ./build
BINDIR := ./bin
INCDIR := ./include
SRCDIR := ./src
TESTDIR := ./test

OBJDIR := $(OUTDIR)/obj
DEPDIR := $(OUTDIR)/dep
EXECUTEFILENAME := $(BINDIR)/$(PROJECTNAME).out
SRCS := $(wildcard $(SRCDIR)/*.c)
TESTS := $(wildcard $(TESTDIR)/*.c)
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS := $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.c=.d))) + $(addprefix $(DEPDIR)/, $(notdir $(TESTS:.c=.d)))

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

.PHONY: all
all : $(EXECUTEFILENAME)

$(EXECUTEFILENAME) : $(OBJS) $(addprefix $(OBJDIR)/, $(notdir $(TESTS:.c=.o))) | $(BINDIR)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@

$(OBJDIR)/%.o : $(TESTDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(DEPFLAGS) $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -c -o $@

include $(wildcard $(DEPS))

$(DEPS) :

$(BINDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

$(DEPDIR):
	@mkdir -p $@

.PHONY: clean
clean :
	$(RM) $(OBJDIR) $(DEPDIR)
	@echo "Remove \"$(OBJDIR) $(DEPDIR)\""

.PHONY: fclean
fclean :
	$(RM) $(EXECUTEFILENAME)
	@echo "Remove \"$(EXECUTEFILENAME)\""

.PHONY: re
re : fclean all

.PHONY: execute
execute :
	$(EXECUTEFILENAME)

.PHONY: debug
debug : CFLAGS += -D_DEBUG
debug : clean fclean $(EXECUTEFILENAME)

.PHONY: lib
lib : $(OBJS)
	@echo "\e[33mGenerate static library(lib$(LIBRARYNAME).a) from $(OBJS)\e[m"
	$(AR) lib$(LIBRARYNAME).a $(OBJS)
	@echo ""

.PHONY: inspect
inspect : lib$(LIBRARYNAME).a
	nm lib$(LIBRARYNAME).a
	@echo ""

.PHONY: help
help :
	@echo "option"
	@echo "  (default) : Compile"
	@echo "        all : Compile"
	@echo "    execute : Execute \"$(EXECUTEFILENAME)\""
	@echo "      clean : Crean (Remove \"$(OBJDIR) $(DEPDIR)\")"
	@echo "     fclean : Crean (Remove \"$(EXECUTEFILENAME)\")"
	@echo "         re : fclean & all"
	@echo "      debug : "
	@echo "        lib : "
	@echo "    inspect : "
	@echo "       help : This"
