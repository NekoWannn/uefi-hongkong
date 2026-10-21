  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

  # Early infrastructure mirrored from the stock a priori list; the ones with
  # source here (DiskIo, Partition, English, Pcd, ArmCpu) are built normally.
  INF hongkongPkg/Binaries/QcomPkg/Drivers/QcomHWWDogDxe/QcomHWWDogDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PlatformExceptionHandlerDxe/PlatformExceptionHandlerDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RngDxe/RngDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/CryptoDxe/CryptoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/Hash2DxeCrypto/Hash2DxeCrypto.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
!endif

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
!endif

  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF hongkongPkg/Drivers/HongkongBootMemoryDxe/HongkongBootMemoryDxe.inf
  # The XNU loader is part of the firmware: a driver loaded from a volume is
  # refused by the image verification of this build.
  INF DarwinBootPkg/Driver/DarwinBoot.inf
  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF FatPkg/EnhancedFatDxe/Fat.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
!endif
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  # The SPMI arbiter is now declared as MMIO in the memory map and the driver
  # uses the base the platform DT actually declares, so its register reads no
  # longer fault.
  INF hongkongPkg/Drivers/HongkongKeyInputDxe/HongkongKeyInputDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

  # Headless until stock sheng framebuffer data is available.
!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

  # USE_CUSTOM_DISPLAY_DRIVER = 1: stock sheng display chain (board DEPEX glue,
  # unchanged vendor DisplayDxe with the N81A panel data from RAW.inc).
  # Otherwise SimpleFbDxe publishes a GOP on the frame buffer the previous
  # stage left scanning out.
!endif
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF hongkongPkg/Drivers/HongkongGopLogDxe/HongkongGopLogDxe.inf
  INF hongkongPkg/Drivers/HongkongDisplayDepexDxe/HongkongDisplayDepexDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  # Headless until stock sheng framebuffer data is available.

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  # USB stack carried over from the device's own volume. The stock modules
  # declare no FFS DEPEX, so their order comes from Include/APRIORI.inc; keep the
  # two lists consistent.
  # UsbPwrCtrlDxe is left out: it reads dynamic PCDs by the token numbers of the
  # vendor build, which do not match ours, and PcdDxe asserts on the size check.
  #INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RNGDxe/RngDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!endif
