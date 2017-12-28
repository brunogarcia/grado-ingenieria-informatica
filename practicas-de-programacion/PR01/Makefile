.PHONY: clean All

All:
	@echo "----------Building project:[ UOCCarLib - Debug ]----------"
	@cd "UOCCarLib" && "$(MAKE)" -f  "UOCCarLib.mk"
	@echo "----------Building project:[ UOCCarServer - Debug ]----------"
	@cd "UOCCarServer" && "$(MAKE)" -f  "UOCCarServer.mk"
clean:
	@echo "----------Cleaning project:[ UOCCarLib - Debug ]----------"
	@cd "UOCCarLib" && "$(MAKE)" -f  "UOCCarLib.mk"  clean
	@echo "----------Cleaning project:[ UOCCarServer - Debug ]----------"
	@cd "UOCCarServer" && "$(MAKE)" -f  "UOCCarServer.mk" clean
