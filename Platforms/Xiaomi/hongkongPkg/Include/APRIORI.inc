APRIORI DXE {
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  # Order below follows the stock volume's a priori list, which puts the watchdog
  # before the PCD database and the exception handler straight after it.
  INF Binaries/hongkong/QcomPkg/Drivers/QcomHWWDogDxe/QcomHWWDogDxe.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PlatformExceptionHandlerDxe/PlatformExceptionHandlerDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  # Crypto comes last in the stock a priori list, after the CPU driver.
  INF Binaries/hongkong/QcomPkg/Drivers/RngDxe/RngDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/CryptoDxe/CryptoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/Hash2DxeCrypto/Hash2DxeCrypto.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
!endif

  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
!endif

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
!endif

  INF FatPkg/EnhancedFatDxe/Fat.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
!endif

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf
!endif
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF hongkongPkg/Drivers/HongkongGopLogDxe/HongkongGopLogDxe.inf
  INF hongkongPkg/Drivers/HongkongDisplayDepexDxe/HongkongDisplayDepexDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif
!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!endif

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  # The carried-over USB modules declare no DEPEX, so this list is what orders
  # them: power and the PCI shim first, then the controller, then the device and
  # storage personalities. Must match Include/DXE.inc.
  INF Binaries/hongkong/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbInitDxe/UsbInitDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/TsensDxe/TsensDxe.inf

  # Headless until stock sheng framebuffer data is available.

  INF Binaries/hongkong/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  # Headless until stock sheng framebuffer data is available.
  INF Binaries/hongkong/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF Binaries/hongkong/QcomPkg/Drivers/RNGDxe/RngDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF Binaries/hongkong/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif
}
