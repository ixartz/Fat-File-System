DIR = src/

all:
	make -C $(DIR)

doc:
	doxygen Doxyfile

clean:
	make -C $(DIR) clean
	rm -Rf doc

.PHONY: doc
