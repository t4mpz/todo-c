GCC_FLAGS= -Wall -Wextra
EXEC_FLAGS= -O2

SOURCE_DIR=./src
OUT_DIR=./out

LIB= $(SOURCE_DIR)/todolib.c

default:
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todo.c -o $(OUT_DIR)/todo
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoAdd.c -o $(OUT_DIR)/todoAdd
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoCount.c -o $(OUT_DIR)/todoCount
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoGet.c -o $(OUT_DIR)/todoGet
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoList.c -o $(OUT_DIR)/todoList
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoReset.c -o $(OUT_DIR)/todoRs
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoRemove.c -o $(OUT_DIR)/todoRm
	gcc $(GCC_FLAGS) $(EXEC_FLAGS) $(LIB) $(SOURCE_DIR)/todoUpdate.c -o $(OUT_DIR)/todoUpdate
lib:
	gcc $(GCC_FLAGS) -fsyntax-only $(LIB)

todo:
	$(OUT_DIR)/todo
todoAdd:
	$(OUT_DIR)/todoAdd
todoCount:
	$(OUT_DIR)/todoCount
todoGet:
	$(OUT_DIR)/todoGet
todoList:
	$(OUT_DIR)/todoList
todoReset:
	$(OUT_DIR)/todoRs
todoRemove:
	$(OUT_DIR)/todoRm
todoUpdate:
	$(OUT_DIR)/todoUpdate
