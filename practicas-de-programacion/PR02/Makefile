.PHONY: clean All

All:
	@echo "----------Building project:[ UOCCarLib - Debug ]----------"
	@cd "UOCCarLib" && "$(MAKE)" -f  "UOCCarLib.mk"
	@echo "----------Building project:[ UOCCarApp - Debug ]----------"
	@cd "UOCCarApp" && "$(MAKE)" -f  "UOCCarApp.mk"
clean:
	@echo "----------Cleaning project:[ UOCCarLib - Debug ]----------"
	@cd "UOCCarLib" && "$(MAKE)" -f  "UOCCarLib.mk"  clean
	@echo "----------Cleaning project:[ UOCCarApp - Debug ]----------"
	@cd "UOCCarApp" && "$(MAKE)" -f  "UOCCarApp.mk" clean
