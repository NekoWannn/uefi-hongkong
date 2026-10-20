// Board raw blobs still come from the stock sheng package: the matching files
// in this device's firmware were not recovered with their original names, and
// the HONGKONG_VENDOR_HW=0 build (Mu drivers plus SimpleFbDxe) does not load
// any of the drivers that read them. Guard them together with the vendor
// hardware switch so the first build does not require files we cannot supply.
!if $(HONGKONG_VENDOR_HW) == 1
  FILE FREEFORM = A1E235DE-E825-4591-9623-C43175811826 {
    SECTION UI = "SecParti.cfg"
    SECTION RAW = Binaries/hongkong/RawFiles/SecParti.cfg
  }

  !if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
    # Stock panel data, original FFS GUIDs and UI names. These are sheng's
    # N81A 3048x2032 blobs; this device's panel XMLs have not been extracted.
    FILE FREEFORM = 15A84758-9EE1-4543-9C82-F430A70F0813 {
      SECTION UI = "Panel_N81A_36_02_0a_p0_duldsi_dsc_vid.xml"
      SECTION RAW = Binaries/hongkong/RawFiles/Panel_N81A_36_02_0a_p0_duldsi_dsc_vid.xml
    }
    FILE FREEFORM = 43013DAA-0CE4-4D82-99EE-17F772A38401 {
      SECTION UI = "Panel_N81A_36_02_0a_duldsi_dsc_vid.xml"
      SECTION RAW = Binaries/hongkong/RawFiles/Panel_N81A_36_02_0a_duldsi_dsc_vid.xml
    }
  !endif
!endif
