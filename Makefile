.PHONY: build
build:
	cd src; $(MAKE);
	cd test; $(MAKE);

.PHONY: clean

clean:
	rm -r build


docker: build
	mkdir docker/release/libds
	cp build/src/libds.a docker/release/libds/libds.a
	cp -r include docker/release/libds
