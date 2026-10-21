APRIORI DXE {
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  # Order below follows the stock volume's a priori list, which puts the watchdog
  # before the PCD database and the exception handler straight after it.
  INF hongkongPkg/Binaries/QcomPkg/Drivers/QcomHWWDogDxe/QcomHWWDogDxe.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PlatformExceptionHandlerDxe/PlatformExceptionHandlerDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  # Crypto comes last in the stock a priori list, after the CPU driver.
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RngDxe/RngDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/CryptoDxe/CryptoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/Hash2DxeCrypto/Hash2DxeCrypto.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
!endif

  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
!endif

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
!endif

  INF FatPkg/EnhancedFatDxe/Fat.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
!endif

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf
!endif
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF hongkongPkg/Drivers/HongkongGopLogDxe/HongkongGopLogDxe.inf
  INF hongkongPkg/Drivers/HongkongDisplayDepexDxe/HongkongDisplayDepexDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif
!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
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
  INF hongkongPkg/Binaries/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

  # The carried-over USB modules declare no DEPEX, so this list is what orders
  # them: power and the PCI shim first, then the controller, then the device and
  # storage personalities. Must match Include/DXE.inc.
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
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
  INF hongkongPkg/Binaries/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/TsensDxe/TsensDxe.inf

  # Headless until stock sheng framebuffer data is available.

  INF hongkongPkg/Binaries/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  # Headless until stock sheng framebuffer data is available.
  INF hongkongPkg/Binaries/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RNGDxe/RngDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

!if $(HONGKONG_VENDOR_HW) == 1
  INF hongkongPkg/Binaries/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif
}
