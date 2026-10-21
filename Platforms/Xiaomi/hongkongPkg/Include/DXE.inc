  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
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
  INF Binaries/hongkong/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
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
  INF Binaries/hongkong/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
!endif
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF hongkongPkg/Drivers/HongkongKeyInputDxe/HongkongKeyInputDxe.inf
  # GraphicsConsoleDxe is left out: it re-sets the GOP mode and clears the panel
  # the moment it starts, so nothing that runs before or after it stays visible.
  # Bring it back once the debug port has another output channel.
  #INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

  # Headless until stock sheng framebuffer data is available.
!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf

  # USE_CUSTOM_DISPLAY_DRIVER = 1: stock sheng display chain (board DEPEX glue,
  # unchanged vendor DisplayDxe with the N81A panel data from RAW.inc).
  # Otherwise SimpleFbDxe publishes a GOP on the frame buffer the previous
  # stage left scanning out.
!endif
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF hongkongPkg/Drivers/HongkongGopLogDxe/HongkongGopLogDxe.inf
  INF hongkongPkg/Drivers/HongkongDisplayDepexDxe/HongkongDisplayDepexDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  # SimpleFbDxe is left out for now: publishing the GOP clears the frame buffer,
  # which erases the debug output written before DXE reaches it. Nothing else
  # needs a GOP while the platform is being brought up.
  #INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif

  # Headless until stock sheng framebuffer data is available.

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TsensDxe/TsensDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/RNGDxe/RngDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!endif
