/*
 *	The PCI Library -- PCI Header Structure (based on <linux/pci.h>)
 *
 *	Copyright (c) 1997--2004 Martin Mares <mj@ucw.cz>
 *
 *	Can be freely distributed and used under the terms of the GNU GPL.
 */

/*
 * Under PCI, each device has 256 bytes of configuration address space,
 * of which the first 64 bytes are standardized as follows:
 */
#define PCI_VENDOR_ID		0x00	/* 16 bits */
#define PCI_DEVICE_ID		0x02	/* 16 bits */
#define PCI_COMMAND		0x04	/* 16 bits */
#define  PCI_COMMAND_IO		0x1	/* Enable response in I/O space */
#define  PCI_COMMAND_MEMORY	0x2	/* Enable response in Memory space */
#define  PCI_COMMAND_MASTER	0x4	/* Enable bus mastering */
#define  PCI_COMMAND_SPECIAL	0x8	/* Enable response to special cycles */
#define  PCI_COMMAND_INVALIDATE	0x10	/* Use memory write and invalidate */
#define  PCI_COMMAND_VGA_PALETTE 0x20	/* Enable palette snooping */
#define  PCI_COMMAND_PARITY	0x40	/* Enable parity checking */
#define  PCI_COMMAND_WAIT 	0x80	/* Enable address/data stepping */
#define  PCI_COMMAND_SERR	0x100	/* Enable SERR */
#define  PCI_COMMAND_FAST_BACK	0x200	/* Enable back-to-back writes */

#define PCI_STATUS		0x06	/* 16 bits */
#define  PCI_STATUS_CAP_LIST	0x10	/* Support Capability List */
#define  PCI_STATUS_66MHZ	0x20	/* Support 66 Mhz PCI 2.1 bus */
#define  PCI_STATUS_UDF		0x40	/* Support User Definable Features [obsolete] */
#define  PCI_STATUS_FAST_BACK	0x80	/* Accept fast-back to back */
#define  PCI_STATUS_PARITY	0x100	/* Detected parity error */
#define  PCI_STATUS_DEVSEL_MASK	0x600	/* DEVSEL timing */
#define  PCI_STATUS_DEVSEL_FAST	0x000	
#define  PCI_STATUS_DEVSEL_MEDIUM 0x200
#define  PCI_STATUS_DEVSEL_SLOW 0x400
#define  PCI_STATUS_SIG_TARGET_ABORT 0x800 /* Set on target abort */
#define  PCI_STATUS_REC_TARGET_ABORT 0x1000 /* Master ack of " */
#define  PCI_STATUS_REC_MASTER_ABORT 0x2000 /* Set on master abort */
#define  PCI_STATUS_SIG_SYSTEM_ERROR 0x4000 /* Set when we drive SERR */
#define  PCI_STATUS_DETECTED_PARITY 0x8000 /* Set on parity error */

#define PCI_CLASS_REVISION	0x08	/* High 24 bits are class, low 8
					   revision */
#define PCI_REVISION_ID         0x08    /* Revision ID */
#define PCI_CLASS_PROG          0x09    /* Reg. Level Programming Interface */
#define PCI_CLASS_DEVICE        0x0a    /* Device class */

#define PCI_CACHE_LINE_SIZE	0x0c	/* 8 bits */
#define PCI_LATENCY_TIMER	0x0d	/* 8 bits */
#define PCI_HEADER_TYPE		0x0e	/* 8 bits */
#define  PCI_HEADER_TYPE_NORMAL	0
#define  PCI_HEADER_TYPE_BRIDGE 1
#define  PCI_HEADER_TYPE_CARDBUS 2

#define PCI_BIST		0x0f	/* 8 bits */
#define PCI_BIST_CODE_MASK	0x0f	/* Return result */
#define PCI_BIST_START		0x40	/* 1 to start BIST, 2 secs or less */
#define PCI_BIST_CAPABLE	0x80	/* 1 if BIST capable */

/*
 * Base addresses specify locations in memory or I/O space.
 * Decoded size can be determined by writing a value of 
 * 0xffffffff to the register, and reading it back.  Only 
 * 1 bits are decoded.
 */
#define PCI_BASE_ADDRESS_0	0x10	/* 32 bits */
#define PCI_BASE_ADDRESS_1	0x14	/* 32 bits [htype 0,1 only] */
#define PCI_BASE_ADDRESS_2	0x18	/* 32 bits [htype 0 only] */
#define PCI_BASE_ADDRESS_3	0x1c	/* 32 bits */
#define PCI_BASE_ADDRESS_4	0x20	/* 32 bits */
#define PCI_BASE_ADDRESS_5	0x24	/* 32 bits */
#define  PCI_BASE_ADDRESS_SPACE	0x01	/* 0 = memory, 1 = I/O */
#define  PCI_BASE_ADDRESS_SPACE_IO 0x01
#define  PCI_BASE_ADDRESS_SPACE_MEMORY 0x00
#define  PCI_BASE_ADDRESS_MEM_TYPE_MASK 0x06
#define  PCI_BASE_ADDRESS_MEM_TYPE_32	0x00	/* 32 bit address */
#define  PCI_BASE_ADDRESS_MEM_TYPE_1M	0x02	/* Below 1M [obsolete] */
#define  PCI_BASE_ADDRESS_MEM_TYPE_64	0x04	/* 64 bit address */
#define  PCI_BASE_ADDRESS_MEM_PREFETCH	0x08	/* prefetchable? */
#define  PCI_BASE_ADDRESS_MEM_MASK	(~(pciaddr_t)0x0f)
#define  PCI_BASE_ADDRESS_IO_MASK	(~(pciaddr_t)0x03)
/* bit 1 is reserved if address_space = 1 */

/* Header type 0 (normal devices) */
#define PCI_CARDBUS_CIS		0x28
#define PCI_SUBSYSTEM_VENDOR_ID	0x2c
#define PCI_SUBSYSTEM_ID	0x2e  
#define PCI_ROM_ADDRESS		0x30	/* Bits 31..11 are address, 10..1 reserved */
#define  PCI_ROM_ADDRESS_ENABLE	0x01
#define PCI_ROM_ADDRESS_MASK	(~(pciaddr_t)0x7ff)

#define PCI_CAPABILITY_LIST	0x34	/* Offset of first capability list entry */

/* 0x35-0x3b are reserved */
#define PCI_INTERRUPT_LINE	0x3c	/* 8 bits */
#define PCI_INTERRUPT_PIN	0x3d	/* 8 bits */
#define PCI_MIN_GNT		0x3e	/* 8 bits */
#define PCI_MAX_LAT		0x3f	/* 8 bits */

/* Header type 1 (PCI-to-PCI bridges) */
#define PCI_PRIMARY_BUS		0x18	/* Primary bus number */
#define PCI_SECONDARY_BUS	0x19	/* Secondary bus number */
#define PCI_SUBORDINATE_BUS	0x1a	/* Highest bus number behind the bridge */
#define PCI_SEC_LATENCY_TIMER	0x1b	/* Latency timer for secondary interface */
#define PCI_IO_BASE		0x1c	/* I/O range behind the bridge */
#define PCI_IO_LIMIT		0x1d
#define  PCI_IO_RANGE_TYPE_MASK	0x0f	/* I/O bridging type */
#define  PCI_IO_RANGE_TYPE_16	0x00
#define  PCI_IO_RANGE_TYPE_32	0x01
#define  PCI_IO_RANGE_MASK	~0x0f
#define PCI_SEC_STATUS		0x1e	/* Secondary status register */
#define PCI_MEMORY_BASE		0x20	/* Memory range behind */
#define PCI_MEMORY_LIMIT	0x22
#define  PCI_MEMORY_RANGE_TYPE_MASK 0x0f
#define  PCI_MEMORY_RANGE_MASK	~0x0f
#define PCI_PREF_MEMORY_BASE	0x24	/* Prefetchable memory range behind */
#define PCI_PREF_MEMORY_LIMIT	0x26
#define  PCI_PREF_RANGE_TYPE_MASK 0x0f
#define  PCI_PREF_RANGE_TYPE_32	0x00
#define  PCI_PREF_RANGE_TYPE_64	0x01
#define  PCI_PREF_RANGE_MASK	~0x0f
#define PCI_PREF_BASE_UPPER32	0x28	/* Upper half of prefetchable memory range */
#define PCI_PREF_LIMIT_UPPER32	0x2c
#define PCI_IO_BASE_UPPER16	0x30	/* Upper half of I/O addresses */
#define PCI_IO_LIMIT_UPPER16	0x32
/* 0x34 same as for htype 0 */
/* 0x35-0x3b is reserved */
#define PCI_ROM_ADDRESS1	0x38	/* Same as PCI_ROM_ADDRESS, but for htype 1 */
/* 0x3c-0x3d are same as for htype 0 */
#define PCI_BRIDGE_CONTROL	0x3e
#define  PCI_BRIDGE_CTL_PARITY	0x01	/* Enable parity detection on secondary interface */
#define  PCI_BRIDGE_CTL_SERR	0x02	/* The same for SERR forwarding */
#define  PCI_BRIDGE_CTL_NO_ISA	0x04	/* Disable bridging of ISA ports */
#define  PCI_BRIDGE_CTL_VGA	0x08	/* Forward VGA addresses */
#define  PCI_BRIDGE_CTL_MASTER_ABORT 0x20  /* Report master aborts */
#define  PCI_BRIDGE_CTL_BUS_RESET 0x40	/* Secondary bus reset */
#define  PCI_BRIDGE_CTL_FAST_BACK 0x80	/* Fast Back2Back enabled on secondary interface */

/* Header type 2 (CardBus bridges) */
/* 0x14-0x15 reserved */
#define PCI_CB_SEC_STATUS	0x16	/* Secondary status */
#define PCI_CB_PRIMARY_BUS	0x18	/* PCI bus number */
#define PCI_CB_CARD_BUS		0x19	/* CardBus bus number */
#define PCI_CB_SUBORDINATE_BUS	0x1a	/* Subordinate bus number */
#define PCI_CB_LATENCY_TIMER	0x1b	/* CardBus latency timer */
#define PCI_CB_MEMORY_BASE_0	0x1c
#define PCI_CB_MEMORY_LIMIT_0	0x20
#define PCI_CB_MEMORY_BASE_1	0x24
#define PCI_CB_MEMORY_LIMIT_1	0x28
#define PCI_CB_IO_BASE_0	0x2c
#define PCI_CB_IO_BASE_0_HI	0x2e
#define PCI_CB_IO_LIMIT_0	0x30
#define PCI_CB_IO_LIMIT_0_HI	0x32
#define PCI_CB_IO_BASE_1	0x34
#define PCI_CB_IO_BASE_1_HI	0x36
#define PCI_CB_IO_LIMIT_1	0x38
#define PCI_CB_IO_LIMIT_1_HI	0x3a
#define  PCI_CB_IO_RANGE_MASK	~0x03
/* 0x3c-0x3d are same as for htype 0 */
#define PCI_CB_BRIDGE_CONTROL	0x3e
#define  PCI_CB_BRIDGE_CTL_PARITY	0x01	/* Similar to standard bridge control register */
#define  PCI_CB_BRIDGE_CTL_SERR		0x02
#define  PCI_CB_BRIDGE_CTL_ISA		0x04
#define  PCI_CB_BRIDGE_CTL_VGA		0x08
#define  PCI_CB_BRIDGE_CTL_MASTER_ABORT	0x20
#define  PCI_CB_BRIDGE_CTL_CB_RESET	0x40	/* CardBus reset */
#define  PCI_CB_BRIDGE_CTL_16BIT_INT	0x80	/* Enable interrupt for 16-bit cards */
#define  PCI_CB_BRIDGE_CTL_PREFETCH_MEM0 0x100	/* Prefetch enable for both memory regions */
#define  PCI_CB_BRIDGE_CTL_PREFETCH_MEM1 0x200
#define  PCI_CB_BRIDGE_CTL_POST_WRITES	0x400
#define PCI_CB_SUBSYSTEM_VENDOR_ID 0x40
#define PCI_CB_SUBSYSTEM_ID	0x42
#define PCI_CB_LEGACY_MODE_BASE	0x44	/* 16-bit PC Card legacy mode base address (ExCa) */
/* 0x48-0x7f reserved */

/* Capability lists */

#define PCI_CAP_LIST_ID		0	/* Capability ID */
#define  PCI_CAP_ID_PM		0x01	/* Power Management */
#define  PCI_CAP_ID_AGP		0x02	/* Accelerated Graphics Port */
#define  PCI_CAP_ID_VPD		0x03	/* Vital Product Data */
#define  PCI_CAP_ID_SLOTID	0x04	/* Slot Identification */
#define  PCI_CAP_ID_MSI		0x05	/* Message Signalled Interrupts */
#define  PCI_CAP_ID_CHSWP	0x06	/* CompactPCI HotSwap */
#define  PCI_CAP_ID_PCIX        0x07    /* PCI-X */
#define  PCI_CAP_ID_HT          0x08    /* HyperTransport */
#define  PCI_CAP_ID_VNDR	0x09	/* Vendor specific */
#define  PCI_CAP_ID_DBG		0x0A	/* Debug port */
#define  PCI_CAP_ID_CCRC	0x0B	/* CompactPCI Central Resource Control */
#define  PCI_CAP_ID_AGP3	0x0E	/* AGP 8x */
#define  PCI_CAP_ID_EXP		0x10	/* PCI Express */
#define  PCI_CAP_ID_MSIX	0x11	/* MSI-X */
#define PCI_CAP_LIST_NEXT	1	/* Next capability in the list */
#define PCI_CAP_FLAGS		2	/* Capability defined flags (16 bits) */
#define PCI_CAP_SIZEOF		4

/* Capabilities residing in the PCI Express extended configuration space */

#define PCI_EXT_CAP_ID_AER	0x01	/* Advanced Error Reporting */
#define PCI_EXT_CAP_ID_VC	0x02	/* Virtual Channel */
#define PCI_EXT_CAP_ID_DSN	0x03	/* Device Serial Number */
#define PCI_EXT_CAP_ID_PB	0x04	/* Power Budgeting */

/* Power Management Registers */

#define  PCI_PM_CAP_VER_MASK	0x0007	/* Version (2=PM1.1) */
#define  PCI_PM_CAP_PME_CLOCK	0x0008	/* Clock required for PME generation */
#define  PCI_PM_CAP_DSI		0x0020	/* Device specific initialization required */
#define  PCI_PM_CAP_AUX_C_MASK	0x01c0	/* Maximum aux current required in D3cold */
#define  PCI_PM_CAP_D1		0x0200	/* D1 power state support */
#define  PCI_PM_CAP_D2		0x0400	/* D2 power state support */
#define  PCI_PM_CAP_PME_D0	0x0800	/* PME can be asserted from D0 */
#define  PCI_PM_CAP_PME_D1	0x1000	/* PME can be asserted from D1 */
#define  PCI_PM_CAP_PME_D2	0x2000	/* PME can be asserted from D2 */
#define  PCI_PM_CAP_PME_D3_HOT	0x4000	/* PME can be asserted from D3hot */
#define  PCI_PM_CAP_PME_D3_COLD	0x8000	/* PME can be asserted from D3cold */
#define PCI_PM_CTRL		4	/* PM control and status register */
#define  PCI_PM_CTRL_STATE_MASK	0x0003	/* Current power state (D0 to D3) */
#define  PCI_PM_CTRL_PME_ENABLE	0x0100	/* PME pin enable */
#define  PCI_PM_CTRL_DATA_SEL_MASK	0x1e00	/* PM table data index */
#define  PCI_PM_CTRL_DATA_SCALE_MASK	0x6000	/* PM table data scaling factor */
#define  PCI_PM_CTRL_PME_STATUS	0x8000	/* PME pin status */
#define PCI_PM_PPB_EXTENSIONS	6	/* PPB support extensions */
#define  PCI_PM_PPB_B2_B3	0x40	/* If bridge enters D3hot, bus enters: 0=B3, 1=B2 */
#define  PCI_PM_BPCC_ENABLE	0x80	/* Secondary bus is power managed */
#define PCI_PM_DATA_REGISTER	7	/* PM table contents read here */
#define PCI_PM_SIZEOF		8

/* AGP registers */

#define PCI_AGP_VERSION		2	/* BCD version number */
#define PCI_AGP_RFU		3	/* Rest of capability flags */
#define PCI_AGP_STATUS		4	/* Status register */
#define  PCI_AGP_STATUS_RQ_MASK	0xff000000	/* Maximum number of requests - 1 */
#define  PCI_AGP_STATUS_ISOCH	0x10000	/* Isochronous transactions supported */
#define  PCI_AGP_STATUS_ARQSZ_MASK	0xe000	/* log2(optimum async req size in bytes) - 4 */
#define  PCI_AGP_STATUS_CAL_MASK	0x1c00	/* Calibration cycle timing */
#define  PCI_AGP_STATUS_SBA	0x0200	/* Sideband addressing supported */
#define  PCI_AGP_STATUS_ITA_COH	0x0100	/* In-aperture accesses always coherent */
#define  PCI_AGP_STATUS_GART64	0x0080	/* 64-bit GART entries supported */
#define  PCI_AGP_STATUS_HTRANS	0x0040	/* If 0, core logic can xlate host CPU accesses thru aperture */
#define  PCI_AGP_STATUS_64BIT	0x0020	/* 64-bit addressing cycles supported */
#define  PCI_AGP_STATUS_FW	0x0010	/* Fast write transfers supported */
#define  PCI_AGP_STATUS_AGP3	0x0008	/* AGP3 mode supported */
#define  PCI_AGP_STATUS_RATE4	0x0004	/* 4x transfer rate supported (RFU in AGP3 mode) */
#define  PCI_AGP_STATUS_RATE2	0x0002	/* 2x transfer rate supported (8x in AGP3 mode) */
#define  PCI_AGP_STATUS_RATE1	0x0001	/* 1x transfer rate supported (4x in AGP3 mode) */
#define PCI_AGP_COMMAND		8	/* Control register */
#define  PCI_AGP_COMMAND_RQ_MASK 0xff000000  /* Master: Maximum number of requests */
#define  PCI_AGP_COMMAND_ARQSZ_MASK	0xe000	/* log2(optimum async req size in bytes) - 4 */
#define  PCI_AGP_COMMAND_CAL_MASK	0x1c00	/* Calibration cycle timing */
#define  PCI_AGP_COMMAND_SBA	0x0200	/* Sideband addressing enabled */
#define  PCI_AGP_COMMAND_AGP	0x0100	/* Allow processing of AGP transactions */
#define  PCI_AGP_COMMAND_GART64	0x0080	/* 64-bit GART entries enabled */
#define  PCI_AGP_COMMAND_64BIT	0x0020 	/* Allow generation of 64-bit addr cycles */
#define  PCI_AGP_COMMAND_FW	0x0010 	/* Enable FW transfers */
#define  PCI_AGP_COMMAND_RATE4	0x0004	/* Use 4x rate (RFU in AGP3 mode) */
#define  PCI_AGP_COMMAND_RATE2	0x0002	/* Use 2x rate (8x in AGP3 mode) */
#define  PCI_AGP_COMMAND_RATE1	0x0001	/* Use 1x rate (4x in AGP3 mode) */
#define PCI_AGP_SIZEOF		12

/* Slot Identification */

#define PCI_SID_ESR		2	/* Expansion Slot Register */
#define  PCI_SID_ESR_NSLOTS	0x1f	/* Number of expansion slots available */
#define  PCI_SID_ESR_FIC	0x20	/* First In Chassis Flag */
#define PCI_SID_CHASSIS_NR	3	/* Chassis Number */

/* Message Signalled Interrupts registers */

#define PCI_MSI_FLAGS		2	/* Various flags */
#define  PCI_MSI_FLAGS_64BIT	0x80	/* 64-bit addresses allowed */
#define  PCI_MSI_FLAGS_QSIZE	0x70	/* Message queue size configured */
#define  PCI_MSI_FLAGS_QMASK	0x0e	/* Maximum queue size available */
#define  PCI_MSI_FLAGS_ENABLE	0x01	/* MSI feature enabled */
#define PCI_MSI_RFU		3	/* Rest of capability flags */
#define PCI_MSI_ADDRESS_LO	4	/* Lower 32 bits */
#define PCI_MSI_ADDRESS_HI	8	/* Upper 32 bits (if PCI_MSI_FLAGS_64BIT set) */
#define PCI_MSI_DATA_32		8	/* 16 bits of data for 32-bit devices */
#define PCI_MSI_DATA_64		12	/* 16 bits of data for 64-bit devices */

/* PCI-X */
#define PCI_PCIX_COMMAND                                                2 /* Command register offset */
#define PCI_PCIX_COMMAND_DPERE                                     0x0001 /* Data Parity Error Recover Enable */
#define PCI_PCIX_COMMAND_ERO                                       0x0002 /* Enable Relaxed Ordering */
#define PCI_PCIX_COMMAND_MAX_MEM_READ_BYTE_COUNT                   0x000c /* Maximum Memory Read Byte Count */
#define PCI_PCIX_COMMAND_MAX_OUTSTANDING_SPLIT_TRANS               0x0070  
#define PCI_PCIX_COMMAND_RESERVED                                   0xf80
#define PCI_PCIX_STATUS                                                 4 /* Status register offset */
#define PCI_PCIX_STATUS_FUNCTION                               0x00000007
#define PCI_PCIX_STATUS_DEVICE                                 0x000000f8
#define PCI_PCIX_STATUS_BUS                                    0x0000ff00
#define PCI_PCIX_STATUS_64BIT                                  0x00010000
#define PCI_PCIX_STATUS_133MHZ                                 0x00020000
#define PCI_PCIX_STATUS_SC_DISCARDED                           0x00040000 /* Split Completion Discarded */
#define PCI_PCIX_STATUS_UNEXPECTED_SC                          0x00080000 /* Unexpected Split Completion */
#define PCI_PCIX_STATUS_DEVICE_COMPLEXITY                      0x00100000 /* 0 = simple device, 1 = bridge device */
#define PCI_PCIX_STATUS_DESIGNED_MAX_MEM_READ_BYTE_COUNT       0x00600000 /* 0 = 512 bytes, 1 = 1024, 2 = 2048, 3 = 4096 */
#define PCI_PCIX_STATUS_DESIGNED_MAX_OUTSTANDING_SPLIT_TRANS   0x03800000
#define PCI_PCIX_STATUS_DESIGNED_MAX_CUMULATIVE_READ_SIZE      0x1c000000
#define PCI_PCIX_STATUS_RCVD_SC_ERR_MESS                       0x20000000 /* Received Split Completion Error Message */
#define PCI_PCIX_STATUS_RESERVED                               0xc0000000
#define PCI_PCIX_SIZEOF		4

/* PCI-X Bridges */
#define PCI_PCIX_BRIDGE_SEC_STATUS                                      2 /* Secondary bus status register offset */
#define PCI_PCIX_BRIDGE_SEC_STATUS_64BIT                           0x0001
#define PCI_PCIX_BRIDGE_SEC_STATUS_133MHZ                          0x0002
#define PCI_PCIX_BRIDGE_SEC_STATUS_SC_DISCARDED                    0x0004 /* Split Completion Discarded on secondary bus */
#define PCI_PCIX_BRIDGE_SEC_STATUS_UNEXPECTED_SC                   0x0008 /* Unexpected Split Completion on secondary bus */
#define PCI_PCIX_BRIDGE_SEC_STATUS_SC_OVERRUN                      0x0010 /* Split Completion Overrun on secondary bus */
#define PCI_PCIX_BRIDGE_SEC_STATUS_SPLIT_REQUEST_DELAYED           0x0020
#define PCI_PCIX_BRIDGE_SEC_STATUS_CLOCK_FREQ                      0x01c0
#define PCI_PCIX_BRIDGE_SEC_STATUS_RESERVED                        0xfe00
#define PCI_PCIX_BRIDGE_STATUS                                          4 /* Primary bus status register offset */
#define PCI_PCIX_BRIDGE_STATUS_FUNCTION                        0x00000007
#define PCI_PCIX_BRIDGE_STATUS_DEVICE                          0x000000f8
#define PCI_PCIX_BRIDGE_STATUS_BUS                             0x0000ff00
#define PCI_PCIX_BRIDGE_STATUS_64BIT                           0x00010000
#define PCI_PCIX_BRIDGE_STATUS_133MHZ                          0x00020000
#define PCI_PCIX_BRIDGE_STATUS_SC_DISCARDED                    0x00040000 /* Split Completion Discarded */
#define PCI_PCIX_BRIDGE_STATUS_UNEXPECTED_SC                   0x00080000 /* Unexpected Split Completion */
#define PCI_PCIX_BRIDGE_STATUS_SC_OVERRUN                      0x00100000 /* Split Completion Overrun */
#define PCI_PCIX_BRIDGE_STATUS_SPLIT_REQUEST_DELAYED           0x00200000
#define PCI_PCIX_BRIDGE_STATUS_RESERVED                        0xffc00000
#define PCI_PCIX_BRIDGE_UPSTREAM_SPLIT_TRANS_CTRL                       8 /* Upstream Split Transaction Register offset */
#define PCI_PCIX_BRIDGE_DOWNSTREAM_SPLIT_TRANS_CTRL                    12 /* Downstream Split Transaction Register offset */
#define PCI_PCIX_BRIDGE_STR_CAPACITY                           0x0000ffff
#define PCI_PCIX_BRIDGE_STR_COMMITMENT_LIMIT                   0xffff0000
#define PCI_PCIX_BRIDGE_SIZEOF 12

/* HyperTransport (as of spec rev. 2.00) */
#define PCI_HT_CMD		2	/* Command Register */
#define  PCI_HT_CMD_TYP_HI	0xe000	/* Capability Type high part */
#define  PCI_HT_CMD_TYP_HI_PRI	0x0000	/* Slave or Primary Interface */
#define  PCI_HT_CMD_TYP_HI_SEC	0x2000	/* Host or Secondary Interface */
#define  PCI_HT_CMD_TYP		0xf800	/* Capability Type */
#define  PCI_HT_CMD_TYP_SW	0x4000	/* Switch */
#define  PCI_HT_CMD_TYP_IDC	0x8000	/* Interrupt Discovery and Configuration */
#define  PCI_HT_CMD_TYP_RID	0x8800	/* Revision ID */
#define  PCI_HT_CMD_TYP_UIDC	0x9000	/* UnitID Clumping */
#define  PCI_HT_CMD_TYP_ECSA	0x9800	/* Extended Configuration Space Access */
#define  PCI_HT_CMD_TYP_AM	0xa000	/* Address Mapping */
#define  PCI_HT_CMD_TYP_MSIM	0xa800	/* MSI Mapping */
#define  PCI_HT_CMD_TYP_DR	0xb000	/* DirectRoute */
#define  PCI_HT_CMD_TYP_VCS	0xb800	/* VCSet */
#define  PCI_HT_CMD_TYP_RM	0xc000	/* Retry Mode */
#define  PCI_HT_CMD_TYP_X86	0xc800	/* X86 (reserved) */

					/* Link Control Register */
#define  PCI_HT_LCTR_CFLE	0x0002	/* CRC Flood Enable */
#define  PCI_HT_LCTR_CST	0x0004	/* CRC Start Test */
#define  PCI_HT_LCTR_CFE	0x0008	/* CRC Force Error */
#define  PCI_HT_LCTR_LKFAIL	0x0010	/* Link Failure */
#define  PCI_HT_LCTR_INIT	0x0020	/* Initialization Complete */
#define  PCI_HT_LCTR_EOC	0x0040	/* End of Chain */
#define  PCI_HT_LCTR_TXO	0x0080	/* Transmitter Off */
#define  PCI_HT_LCTR_CRCERR	0x0f00	/* CRC Error */
#define  PCI_HT_LCTR_ISOCEN	0x1000	/* Isochronous Flow Control Enable */
#define  PCI_HT_LCTR_LSEN	0x2000	/* LDTSTOP# Tristate Enable */
#define  PCI_HT_LCTR_EXTCTL	0x4000	/* Extended CTL Time */
#define  PCI_HT_LCTR_64B	0x8000	/* 64-bit Addressing Enable */

					/* Link Configuration Register */
#define  PCI_HT_LCNF_MLWI	0x0007	/* Max Link Width In */
#define  PCI_HT_LCNF_LW_8B	0x0	/* Link Width 8 bits */
#define  PCI_HT_LCNF_LW_16B	0x1	/* Link Width 16 bits */
#define  PCI_HT_LCNF_LW_32B	0x3	/* Link Width 32 bits */
#define  PCI_HT_LCNF_LW_2B	0x4	/* Link Width 2 bits */
#define  PCI_HT_LCNF_LW_4B	0x5	/* Link Width 4 bits */
#define  PCI_HT_LCNF_LW_NC	0x7	/* Link physically not connected */
#define  PCI_HT_LCNF_DFI	0x0008	/* Doubleword Flow Control In */
#define  PCI_HT_LCNF_MLWO	0x0070	/* Max Link Width Out */
#define  PCI_HT_LCNF_DFO	0x0080	/* Doubleword Flow Control Out */
#define  PCI_HT_LCNF_LWI	0x0700	/* Link Width In */
#define  PCI_HT_LCNF_DFIE	0x0800	/* Doubleword Flow Control In Enable */
#define  PCI_HT_LCNF_LWO	0x7000	/* Link Width Out */
#define  PCI_HT_LCNF_DFOE	0x8000	/* Doubleword Flow Control Out Enable */

					/* Revision ID Register */
#define  PCI_HT_RID_MIN		0x1f	/* Minor Revision */
#define  PCI_HT_RID_MAJ		0xe0	/* Major Revision */

					/* Link Frequency/Error Register */
#define  PCI_HT_LFRER_FREQ	0x0f	/* Transmitter Clock Frequency */
#define  PCI_HT_LFRER_200	0x00	/* 200MHz */
#define  PCI_HT_LFRER_300	0x01	/* 300MHz */
#define  PCI_HT_LFRER_400	0x02	/* 400MHz */
#define  PCI_HT_LFRER_500	0x03	/* 500MHz */
#define  PCI_HT_LFRER_600	0x04	/* 600MHz */
#define  PCI_HT_LFRER_800	0x05	/* 800MHz */
#define  PCI_HT_LFRER_1000	0x06	/* 1.0GHz */
#define  PCI_HT_LFRER_1200	0x07	/* 1.2GHz */
#define  PCI_HT_LFRER_1400	0x08	/* 1.4GHz */
#define  PCI_HT_LFRER_1600	0x09	/* 1.6GHz */
#define  PCI_HT_LFRER_VEND	0x0f	/* Vendor-Specific */
#define  PCI_HT_LFRER_ERR	0xf0	/* Link Error */
#define  PCI_HT_LFRER_PROT	0x10	/* Protocol Error */
#define  PCI_HT_LFRER_OV	0x20	/* Overflow Error */
#define  PCI_HT_LFRER_EOC	0x40	/* End of Chain Error */
#define  PCI_HT_LFRER_CTLT	0x80	/* CTL Timeout */

					/* Link Frequency Capability Register */
#define  PCI_HT_LFCAP_200	0x0001	/* 200MHz */
#define  PCI_HT_LFCAP_300	0x0002	/* 300MHz */
#define  PCI_HT_LFCAP_400	0x0004	/* 400MHz */
#define  PCI_HT_LFCAP_500	0x0008	/* 500MHz */
#define  PCI_HT_LFCAP_600	0x0010	/* 600MHz */
#define  PCI_HT_LFCAP_800	0x0020	/* 800MHz */
#define  PCI_HT_LFCAP_1000	0x0040	/* 1.0GHz */
#define  PCI_HT_LFCAP_1200	0x0080	/* 1.2GHz */
#define  PCI_HT_LFCAP_1400	0x0100	/* 1.4GHz */
#define  PCI_HT_LFCAP_1600	0x0200	/* 1.6GHz */
#define  PCI_HT_LFCAP_VEND	0x8000	/* Vendor-Specific */

					/* Feature Register */
#define  PCI_HT_FTR_ISOCFC	0x0001	/* Isochronous Flow Control Mode */
#define  PCI_HT_FTR_LDTSTOP	0x0002	/* LDTSTOP# Supported */
#define  PCI_HT_FTR_CRCTM	0x0004	/* CRC Test Mode */
#define  PCI_HT_FTR_ECTLT	0x0008	/* Extended CTL Time Required */
#define  PCI_HT_FTR_64BA	0x0010	/* 64-bit Addressing */
#define  PCI_HT_FTR_UIDRD	0x0020	/* UnitID Reorder Disable */

					/* Error Handling Register */
#define  PCI_HT_EH_PFLE		0x0001	/* Protocol Error Flood Enable */
#define  PCI_HT_EH_OFLE		0x0002	/* Overflow Error Flood Enable */
#define  PCI_HT_EH_PFE		0x0004	/* Protocol Error Fatal Enable */
#define  PCI_HT_EH_OFE		0x0008	/* Overflow Error Fatal Enable */
#define  PCI_HT_EH_EOCFE	0x0010	/* End of Chain Error Fatal Enable */
#define  PCI_HT_EH_RFE		0x0020	/* Response Error Fatal Enable */
#define  PCI_HT_EH_CRCFE	0x0040	/* CRC Error Fatal Enable */
#define  PCI_HT_EH_SERRFE	0x0080	/* System Error Fatal Enable (B */
#define  PCI_HT_EH_CF		0x0100	/* Chain Fail */
#define  PCI_HT_EH_RE		0x0200	/* Response Error */
#define  PCI_HT_EH_PNFE		0x0400	/* Protocol Error Nonfatal Enable */
#define  PCI_HT_EH_ONFE		0x0800	/* Overflow Error Nonfatal Enable */
#define  PCI_HT_EH_EOCNFE	0x1000	/* End of Chain Error Nonfatal Enable */
#define  PCI_HT_EH_RNFE		0x2000	/* Response Error Nonfatal Enable */
#define  PCI_HT_EH_CRCNFE	0x4000	/* CRC Error Nonfatal Enable */
#define  PCI_HT_EH_SERRNFE	0x8000	/* System Error Nonfatal Enable */

/* HyperTransport: Slave or Primary Interface */
#define PCI_HT_PRI_CMD		2	/* Command Register */
#define  PCI_HT_PRI_CMD_BUID	0x001f	/* Base UnitID */
#define  PCI_HT_PRI_CMD_UC	0x03e0	/* Unit Count */
#define  PCI_HT_PRI_CMD_MH	0x0400	/* Master Host */
#define  PCI_HT_PRI_CMD_DD	0x0800	/* Default Direction */
#define  PCI_HT_PRI_CMD_DUL	0x1000	/* Drop on Uninitialized Link */

#define PCI_HT_PRI_LCTR0	4	/* Link Control 0 Register */
#define PCI_HT_PRI_LCNF0	6	/* Link Config 0 Register */
#define PCI_HT_PRI_LCTR1	8	/* Link Control 1 Register */
#define PCI_HT_PRI_LCNF1	10	/* Link Config 1 Register */
#define PCI_HT_PRI_RID		12	/* Revision ID Register */
#define PCI_HT_PRI_LFRER0	13	/* Link Frequency/Error 0 Register */
#define PCI_HT_PRI_LFCAP0	14	/* Link Frequency Capability 0 Register */
#define PCI_HT_PRI_FTR		16	/* Feature Register */
#define PCI_HT_PRI_LFRER1	17	/* Link Frequency/Error 1 Register */
#define PCI_HT_PRI_LFCAP1	18	/* Link Frequency Capability 1 Register */
#define PCI_HT_PRI_ES		20	/* Enumeration Scratchpad Register */
#define PCI_HT_PRI_EH		22	/* Error Handling Register */
#define PCI_HT_PRI_MBU		24	/* Memory Base Upper Register */
#define PCI_HT_PRI_MLU		25	/* Memory Limit Upper Register */
#define PCI_HT_PRI_BN		26	/* Bus Number Register */
#define PCI_HT_PRI_SIZEOF	28

/* HyperTransport: Host or Secondary Interface */
#define PCI_HT_SEC_CMD		2	/* Command Register */
#define  PCI_HT_SEC_CMD_WR	0x0001	/* Warm Reset */
#define  PCI_HT_SEC_CMD_DE	0x0002	/* Double-Ended */
#define  PCI_HT_SEC_CMD_DN	0x0076	/* Device Number */
#define  PCI_HT_SEC_CMD_CS	0x0080	/* Chain Side */
#define  PCI_HT_SEC_CMD_HH	0x0100	/* Host Hide */
#define  PCI_HT_SEC_CMD_AS	0x0400	/* Act as Slave */
#define  PCI_HT_SEC_CMD_HIECE	0x0800	/* Host Inbound End of Chain Error */
#define  PCI_HT_SEC_CMD_DUL	0x1000	/* Drop on Uninitialized Link */

#define PCI_HT_SEC_LCTR		4	/* Link Control Register */
#define PCI_HT_SEC_LCNF		6	/* Link Config Register */
#define PCI_HT_SEC_RID		8	/* Revision ID Register */
#define PCI_HT_SEC_LFRER	9	/* Link Frequency/Error Register */
#define PCI_HT_SEC_LFCAP	10	/* Link Frequency Capability Register */
#define PCI_HT_SEC_FTR		12	/* Feature Register */
#define  PCI_HT_SEC_FTR_EXTRS	0x0100	/* Extended Register Set */
#define  PCI_HT_SEC_FTR_UCNFE	0x0200	/* Upstream Configuration Enable */
#define PCI_HT_SEC_ES		16	/* Enumeration Scratchpad Register */
#define PCI_HT_SEC_EH		18	/* Error Handling Register */
#define PCI_HT_SEC_MBU		20	/* Memory Base Upper Register */
#define PCI_HT_SEC_MLU		21	/* Memory Limit Upper Register */
#define PCI_HT_SEC_SIZEOF	24

/* HyperTransport: Switch */
#define PCI_HT_SW_CMD		2	/* Switch Command Register */
#define  PCI_HT_SW_CMD_VIBERR	0x0080	/* VIB Error */
#define  PCI_HT_SW_CMD_VIBFL	0x0100	/* VIB Flood */
#define  PCI_HT_SW_CMD_VIBFT	0x0200	/* VIB Fatal */
#define  PCI_HT_SW_CMD_VIBNFT	0x0400	/* VIB Nonfatal */
#define PCI_HT_SW_PMASK		4	/* Partition Mask Register */
#define PCI_HT_SW_SWINF		8	/* Switch Info Register */
#define  PCI_HT_SW_SWINF_DP	0x0000001f /* Default Port */
#define  PCI_HT_SW_SWINF_EN	0x00000020 /* Enable Decode */
#define  PCI_HT_SW_SWINF_CR	0x00000040 /* Cold Reset */
#define  PCI_HT_SW_SWINF_PCIDX	0x00000f00 /* Performance Counter Index */
#define  PCI_HT_SW_SWINF_BLRIDX	0x0003f000 /* Base/Limit Range Index */
#define  PCI_HT_SW_SWINF_SBIDX	0x00002000 /* Secondary Base Range Index */
#define  PCI_HT_SW_SWINF_HP	0x00040000 /* Hot Plug */
#define  PCI_HT_SW_SWINF_HIDE	0x00080000 /* Hide Port */
#define PCI_HT_SW_PCD		12	/* Performance Counter Data Register */
#define PCI_HT_SW_BLRD		16	/* Base/Limit Range Data Register */
#define PCI_HT_SW_SBD		20	/* Secondary Base Data Register */
#define PCI_HT_SW_SIZEOF	24

					/* Counter indices */
#define  PCI_HT_SW_PC_PCR	0x0	/* Posted Command Receive */
#define  PCI_HT_SW_PC_NPCR	0x1	/* Nonposted Command Receive */
#define  PCI_HT_SW_PC_RCR	0x2	/* Response Command Receive */
#define  PCI_HT_SW_PC_PDWR	0x3	/* Posted DW Receive */
#define  PCI_HT_SW_PC_NPDWR	0x4	/* Nonposted DW Receive */
#define  PCI_HT_SW_PC_RDWR	0x5	/* Response DW Receive */
#define  PCI_HT_SW_PC_PCT	0x6	/* Posted Command Transmit */
#define  PCI_HT_SW_PC_NPCT	0x7	/* Nonposted Command Transmit */
#define  PCI_HT_SW_PC_RCT	0x8	/* Response Command Transmit */
#define  PCI_HT_SW_PC_PDWT	0x9	/* Posted DW Transmit */
#define  PCI_HT_SW_PC_NPDWT	0xa	/* Nonposted DW Transmit */
#define  PCI_HT_SW_PC_RDWT	0xb	/* Response DW Transmit */

					/* Base/Limit Range indices */
#define  PCI_HT_SW_BLR_BASE0_LO	0x0	/* Base 0[31:1], Enable */
#define  PCI_HT_SW_BLR_BASE0_HI	0x1	/* Base 0 Upper */
#define  PCI_HT_SW_BLR_LIM0_LO	0x2	/* Limit 0 Lower */
#define  PCI_HT_SW_BLR_LIM0_HI	0x3	/* Limit 0 Upper */

					/* Secondary Base indices */
#define  PCI_HT_SW_SB_LO	0x0	/* Secondary Base[31:1], Enable */
#define  PCI_HT_SW_S0_HI	0x1	/* Secondary Base Upper */

/* HyperTransport: Interrupt Discovery and Configuration */
#define PCI_HT_IDC_IDX		2	/* Index Register */
#define PCI_HT_IDC_DATA		4	/* Data Register */
#define PCI_HT_IDC_SIZEOF	8

					/* Register indices */
#define  PCI_HT_IDC_IDX_LINT	0x01	/* Last Interrupt Register */
#define   PCI_HT_IDC_LINT	0x00ff0000 /* Last interrupt definition */
#define  PCI_HT_IDC_IDX_IDR	0x10	/* Interrupt Definition Registers */
					/* Low part (at index) */
#define   PCI_HT_IDC_IDR_MASK	0x10000001 /* Mask */
#define   PCI_HT_IDC_IDR_POL	0x10000002 /* Polarity */
#define   PCI_HT_IDC_IDR_II_2	0x1000001c /* IntrInfo[4:2]: Message Type */
#define   PCI_HT_IDC_IDR_II_5	0x10000020 /* IntrInfo[5]: Request EOI */
#define   PCI_HT_IDC_IDR_II_6	0x00ffffc0 /* IntrInfo[23:6] */
#define   PCI_HT_IDC_IDR_II_24	0xff000000 /* IntrInfo[31:24] */
					/* High part (at index + 1) */
#define   PCI_HT_IDC_IDR_II_32	0x00ffffff /* IntrInfo[55:32] */
#define   PCI_HT_IDC_IDR_PASSPW	0x40000000 /* PassPW setting for messages */
#define   PCI_HT_IDC_IDR_WEOI	0x80000000 /* Waiting for EOI */

/* HyperTransport: Revision ID */
#define PCI_HT_RID_RID		2	/* Revision Register */
#define PCI_HT_RID_SIZEOF	4

/* HyperTransport: UnitID Clumping */
#define PCI_HT_UIDC_CS		4	/* Clumping Support Register */
#define PCI_HT_UIDC_CE		8	/* Clumping Enable Register */
#define PCI_HT_UIDC_SIZEOF	12

/* HyperTransport: Extended Configuration Space Access */
#define PCI_HT_ECSA_ADDR	4	/* Configuration Address Register */
#define  PCI_HT_ECSA_ADDR_REG	0x00000ffc /* Register */
#define  PCI_HT_ECSA_ADDR_FUN	0x00007000 /* Function */
#define  PCI_HT_ECSA_ADDR_DEV	0x000f1000 /* Device */
#define  PCI_HT_ECSA_ADDR_BUS	0x0ff00000 /* Bus Number */
#define  PCI_HT_ECSA_ADDR_TYPE	0x10000000 /* Access Type */
#define PCI_HT_ECSA_DATA	8	/* Configuration Data Register */
#define PCI_HT_ECSA_SIZEOF	12

/* HyperTransport: Address Mapping */
#define PCI_HT_AM_CMD		2	/* Command Register */
#define  PCI_HT_AM_CMD_NDMA	0x000f	/* Number of DMA Mappings */
#define  PCI_HT_AM_CMD_IOSIZ	0x01f0	/* I/O Size */
#define  PCI_HT_AM_CMD_MT	0x0600	/* Map Type */
#define  PCI_HT_AM_CMD_MT_40B	0x0000	/* 40-bit */
#define  PCI_HT_AM_CMD_MT_64B	0x0200	/* 64-bit */

					/* Window Control Register bits */
#define  PCI_HT_AM_SBW_CTR_COMP	0x1	/* Compat */
#define  PCI_HT_AM_SBW_CTR_NCOH	0x2	/* NonCoherent */
#define  PCI_HT_AM_SBW_CTR_ISOC	0x4	/* Isochronous */
#define  PCI_HT_AM_SBW_CTR_EN	0x8	/* Enable */

/* HyperTransport: 40-bit Address Mapping */
#define PCI_HT_AM40_SBNPW	4	/* Secondary Bus Non-Prefetchable Window Register */
#define  PCI_HT_AM40_SBW_BASE	0x000fffff /* Window Base */
#define  PCI_HT_AM40_SBW_CTR	0xf0000000 /* Window Control */
#define PCI_HT_AM40_SBPW	8	/* Secondary Bus Prefetchable Window Register */
#define PCI_HT_AM40_DMA_PBASE0	12	/* DMA Window Primary Base 0 Register */
#define PCI_HT_AM40_DMA_CTR0	15	/* DMA Window Control 0 Register */
#define  PCI_HT_AM40_DMA_CTR_CTR 0xf0	/* Window Control */
#define PCI_HT_AM40_DMA_SLIM0	16	/* DMA Window Secondary Limit 0 Register */
#define PCI_HT_AM40_DMA_SBASE0	18	/* DMA Window Secondary Base 0 Register */
#define PCI_HT_AM40_SIZEOF	12	/* size is variable: 12 + 8 * NDMA */

/* HyperTransport: 64-bit Address Mapping */
#define PCI_HT_AM64_IDX		4	/* Index Register */
#define PCI_HT_AM64_DATA_LO	8	/* Data Lower Register */
#define PCI_HT_AM64_DATA_HI	12	/* Data Upper Register */
#define PCI_HT_AM64_SIZEOF	16

					/* Register indices */
#define  PCI_HT_AM64_IDX_SBNPW	0x00	/* Secondary Bus Non-Prefetchable Window Register */
#define   PCI_HT_AM64_W_BASE_LO	0xfff00000 /* Window Base Lower */
#define   PCI_HT_AM64_W_CTR	0x0000000f /* Window Control */
#define  PCI_HT_AM64_IDX_SBPW	0x01	/* Secondary Bus Prefetchable Window Register */
#define   PCI_HT_AM64_IDX_PBNPW	0x02	/* Primary Bus Non-Prefetchable Window Register */
#define   PCI_HT_AM64_IDX_DMAPB0 0x04	/* DMA Window Primary Base 0 Register */
#define   PCI_HT_AM64_IDX_DMASB0 0x05	/* DMA Window Secondary Base 0 Register */
#define   PCI_HT_AM64_IDX_DMASL0 0x06	/* DMA Window Secondary Limit 0 Register */

/* HyperTransport: MSI Mapping */
#define PCI_HT_MSIM_CMD		2	/* Command Register */
#define  PCI_HT_MSIM_CMD_EN	0x0001	/* Mapping Active */
#define  PCI_HT_MSIM_CMD_FIXD	0x0002	/* MSI Mapping Address Fixed */
#define PCI_HT_MSIM_ADDR_LO	4	/* MSI Mapping Address Lower Register */
#define PCI_HT_MSIM_ADDR_HI	8	/* MSI Mapping Address Upper Register */
#define PCI_HT_MSIM_SIZEOF	12

/* HyperTransport: DirectRoute */
#define PCI_HT_DR_CMD		2	/* Command Register */
#define  PCI_HT_DR_CMD_NDRS	0x000f	/* Number of DirectRoute Spaces */
#define  PCI_HT_DR_CMD_IDX	0x01f0	/* Index */
#define PCI_HT_DR_EN		4	/* Enable Vector Register */
#define PCI_HT_DR_DATA		8	/* Data Register */
#define PCI_HT_DR_SIZEOF	12

					/* Register indices */
#define  PCI_HT_DR_IDX_BASE_LO	0x00	/* DirectRoute Base Lower Register */
#define   PCI_HT_DR_OTNRD	0x00000001 /* Opposite to Normal Request Direction */
#define   PCI_HT_DR_BL_LO	0xffffff00 /* Base/Limit Lower */
#define  PCI_HT_DR_IDX_BASE_HI	0x01	/* DirectRoute Base Upper Register */
#define  PCI_HT_DR_IDX_LIMIT_LO	0x02	/* DirectRoute Limit Lower Register */
#define  PCI_HT_DR_IDX_LIMIT_HI	0x03	/* DirectRoute Limit Upper Register */

/* HyperTransport: VCSet */
#define PCI_HT_VCS_SUP		4	/* VCSets Supported Register */
#define PCI_HT_VCS_L1EN		5	/* Link 1 VCSets Enabled Register */
#define PCI_HT_VCS_L0EN		6	/* Link 0 VCSets Enabled Register */
#define PCI_HT_VCS_SBD		8	/* Stream Bucket Depth Register */
#define PCI_HT_VCS_SINT		9	/* Stream Interval Register */
#define PCI_HT_VCS_SSUP		10	/* Number of Streaming VCs Supported Register */
#define  PCI_HT_VCS_SSUP_0	0x00	/* Streaming VC 0 */
#define  PCI_HT_VCS_SSUP_3	0x01	/* Streaming VCs 0-3 */
#define  PCI_HT_VCS_SSUP_15	0x02	/* Streaming VCs 0-15 */
#define PCI_HT_VCS_NFCBD	12	/* Non-FC Bucket Depth Register */
#define PCI_HT_VCS_NFCINT	13	/* Non-FC Bucket Interval Register */
#define PCI_HT_VCS_SIZEOF	16

/* HyperTransport: Retry Mode */
#define PCI_HT_RM_CTR0		4	/* Control 0 Register */
#define  PCI_HT_RM_CTR_LRETEN	0x01	/* Link Retry Enable */
#define  PCI_HT_RM_CTR_FSER	0x02	/* Force Single Error */
#define  PCI_HT_RM_CTR_ROLNEN	0x04	/* Rollover Nonfatal Enable */
#define  PCI_HT_RM_CTR_FSS	0x08	/* Force Single Stomp */
#define  PCI_HT_RM_CTR_RETNEN	0x10	/* Retry Nonfatal Enable */
#define  PCI_HT_RM_CTR_RETFEN	0x20	/* Retry Fatal Enable */
#define  PCI_HT_RM_CTR_AA	0xc0	/* Allowed Attempts */
#define PCI_HT_RM_STS0		5	/* Status 0 Register */
#define  PCI_HT_RM_STS_RETSNT	0x01	/* Retry Sent */
#define  PCI_HT_RM_STS_CNTROL	0x02	/* Count Rollover */
#define  PCI_HT_RM_STS_SRCV	0x04	/* Stomp Received */
#define PCI_HT_RM_CTR1		6	/* Control 1 Register */
#define PCI_HT_RM_STS1		7	/* Status 1 Register */
#define PCI_HT_RM_CNT0		8	/* Retry Count 0 Register */
#define PCI_HT_RM_CNT1		10	/* Retry Count 1 Register */
#define PCI_HT_RM_SIZEOF	12

/* PCI Express */
#define PCI_EXP_FLAGS		0x2	/* Capabilities register */
#define PCI_EXP_FLAGS_VERS	0x000f	/* Capability version */
#define PCI_EXP_FLAGS_TYPE	0x00f0	/* Device/Port type */
#define  PCI_EXP_TYPE_ENDPOINT	0x0	/* Express Endpoint */
#define  PCI_EXP_TYPE_LEG_END	0x1	/* Legacy Endpoint */
#define  PCI_EXP_TYPE_ROOT_PORT 0x4	/* Root Port */
#define  PCI_EXP_TYPE_UPSTREAM	0x5	/* Upstream Port */
#define  PCI_EXP_TYPE_DOWNSTREAM 0x6	/* Downstream Port */
#define  PCI_EXP_TYPE_PCI_BRIDGE 0x7	/* PCI/PCI-X Bridge */
#define PCI_EXP_FLAGS_SLOT	0x0100	/* Slot implemented */
#define PCI_EXP_FLAGS_IRQ	0x3e00	/* Interrupt message number */
#define PCI_EXP_DEVCAP		0x4	/* Device capabilities */
#define  PCI_EXP_DEVCAP_PAYLOAD	0x07	/* Max_Payload_Size */
#define  PCI_EXP_DEVCAP_PHANTOM	0x18	/* Phantom functions */
#define  PCI_EXP_DEVCAP_EXT_TAG	0x20	/* Extended tags */
#define  PCI_EXP_DEVCAP_L0S	0x1c0	/* L0s Acceptable Latency */
#define  PCI_EXP_DEVCAP_L1	0xe00	/* L1 Acceptable Latency */
#define  PCI_EXP_DEVCAP_ATN_BUT	0x1000	/* Attention Button Present */
#define  PCI_EXP_DEVCAP_ATN_IND	0x2000	/* Attention Indicator Present */
#define  PCI_EXP_DEVCAP_PWR_IND	0x4000	/* Power Indicator Present */
#define  PCI_EXP_DEVCAP_PWR_VAL	0x3fc0000 /* Slot Power Limit Value */
#define  PCI_EXP_DEVCAP_PWR_SCL	0xc000000 /* Slot Power Limit Scale */
#define PCI_EXP_DEVCTL		0x8	/* Device Control */
#define  PCI_EXP_DEVCTL_CERE	0x0001	/* Correctable Error Reporting En. */
#define  PCI_EXP_DEVCTL_NFERE	0x0002	/* Non-Fatal Error Reporting Enable */
#define  PCI_EXP_DEVCTL_FERE	0x0004	/* Fatal Error Reporting Enable */
#define  PCI_EXP_DEVCTL_URRE	0x0008	/* Unsupported Request Reporting En. */
#define  PCI_EXP_DEVCTL_RELAXED	0x0010	/* Enable Relaxed Ordering */
#define  PCI_EXP_DEVCTL_PAYLOAD	0x00e0	/* Max_Payload_Size */
#define  PCI_EXP_DEVCTL_EXT_TAG	0x0100	/* Extended Tag Field Enable */
#define  PCI_EXP_DEVCTL_PHANTOM	0x0200	/* Phantom Functions Enable */
#define  PCI_EXP_DEVCTL_AUX_PME	0x0400	/* Auxiliary Power PM Enable */
#define  PCI_EXP_DEVCTL_NOSNOOP	0x0800	/* Enable No Snoop */
#define  PCI_EXP_DEVCTL_READRQ	0x7000	/* Max_Read_Request_Size */
#define PCI_EXP_DEVSTA		0xa	/* Device Status */
#define  PCI_EXP_DEVSTA_CED	0x01	/* Correctable Error Detected */
#define  PCI_EXP_DEVSTA_NFED	0x02	/* Non-Fatal Error Detected */
#define  PCI_EXP_DEVSTA_FED	0x04	/* Fatal Error Detected */
#define  PCI_EXP_DEVSTA_URD	0x08	/* Unsupported Request Detected */
#define  PCI_EXP_DEVSTA_AUXPD	0x10	/* AUX Power Detected */
#define  PCI_EXP_DEVSTA_TRPND	0x20	/* Transactions Pending */
#define PCI_EXP_LNKCAP		0xc	/* Link Capabilities */
#define  PCI_EXP_LNKCAP_SPEED	0x0000f	/* Maximum Link Speed */
#define  PCI_EXP_LNKCAP_WIDTH	0x003f0	/* Maximum Link Width */
#define  PCI_EXP_LNKCAP_ASPM	0x00c00	/* Active State Power Management */
#define  PCI_EXP_LNKCAP_L0S	0x07000	/* L0s Acceptable Latency */
#define  PCI_EXP_LNKCAP_L1	0x38000	/* L1 Acceptable Latency */
#define  PCI_EXP_LNKCAP_PORT	0xff000000 /* Port Number */
#define PCI_EXP_LNKCTL		0x10	/* Link Control */
#define  PCI_EXP_LNKCTL_ASPM	0x0003	/* ASPM Control */
#define  PCI_EXP_LNKCTL_RCB	0x0008	/* Read Completion Boundary */
#define  PCI_EXP_LNKCTL_DISABLE	0x0010	/* Link Disable */
#define  PCI_EXP_LNKCTL_RETRAIN	0x0020	/* Retrain Link */
#define  PCI_EXP_LNKCTL_CLOCK	0x0040	/* Common Clock Configuration */
#define  PCI_EXP_LNKCTL_XSYNCH	0x0080	/* Extended Synch */
#define PCI_EXP_LNKSTA		0x12	/* Link Status */
#define  PCI_EXP_LNKSTA_SPEED	0x000f	/* Negotiated Link Speed */
#define  PCI_EXP_LNKSTA_WIDTH	0x03f0	/* Negotiated Link Width */
#define  PCI_EXP_LNKSTA_TR_ERR	0x0400	/* Training Error */
#define  PCI_EXP_LNKSTA_TRAIN	0x0800	/* Link Training */
#define  PCI_EXP_LNKSTA_SL_CLK	0x1000	/* Slot Clock Configuration */
#define PCI_EXP_SLTCAP		0x14	/* Slot Capabilities */
#define  PCI_EXP_SLTCAP_ATNB	0x0001	/* Attention Button Present */
#define  PCI_EXP_SLTCAP_PWRC	0x0002	/* Power Controller Present */
#define  PCI_EXP_SLTCAP_MRL	0x0004	/* MRL Sensor Present */
#define  PCI_EXP_SLTCAP_ATNI	0x0008	/* Attention Indicator Present */
#define  PCI_EXP_SLTCAP_PWRI	0x0010	/* Power Indicator Present */
#define  PCI_EXP_SLTCAP_HPS	0x0020	/* Hot-Plug Surprise */
#define  PCI_EXP_SLTCAP_HPC	0x0040	/* Hot-Plug Capable */
#define  PCI_EXP_SLTCAP_PWR_VAL	0x00007f80 /* Slot Power Limit Value */
#define  PCI_EXP_SLTCAP_PWR_SCL	0x00018000 /* Slot Power Limit Scale */
#define  PCI_EXP_SLTCAP_PSN	0xfff80000 /* Physical Slot Number */
#define PCI_EXP_SLTCTL		0x18	/* Slot Control */
#define  PCI_EXP_SLTCTL_ATNB	0x0001	/* Attention Button Pressed Enable */
#define  PCI_EXP_SLTCTL_PWRF	0x0002	/* Power Fault Detected Enable */
#define  PCI_EXP_SLTCTL_MRLS	0x0004	/* MRL Sensor Changed Enable */
#define  PCI_EXP_SLTCTL_PRSD	0x0008	/* Presence Detect Changed Enable */
#define  PCI_EXP_SLTCTL_CMDC	0x0010	/* Command Completed Interrupt Enable */
#define  PCI_EXP_SLTCTL_HPIE	0x0020	/* Hot-Plug Interrupt Enable */
#define  PCI_EXP_SLTCTL_ATNI	0x00C0	/* Attention Indicator Control */
#define  PCI_EXP_SLTCTL_PWRI	0x0300	/* Power Indicator Control */
#define  PCI_EXP_SLTCTL_PWRC	0x0400	/* Power Controller Control */
#define PCI_EXP_SLTSTA		0x1a	/* Slot Status */
#define PCI_EXP_RTCTL		0x1c	/* Root Control */
#define  PCI_EXP_RTCTL_SECEE	0x1	/* System Error on Correctable Error */
#define  PCI_EXP_RTCTL_SENFEE	0x1	/* System Error on Non-Fatal Error */
#define  PCI_EXP_RTCTL_SEFEE	0x1	/* System Error on Fatal Error */
#define  PCI_EXP_RTCTL_PMEIE	0x1	/* PME Interrupt Enable */
#define PCI_EXP_RTSTA		0x20	/* Root Status */

/* MSI-X */
#define  PCI_MSIX_ENABLE	0x8000
#define  PCI_MSIX_MASK		0x4000
#define  PCI_MSIX_TABSIZE	0x03ff
#define PCI_MSIX_TABLE		4
#define PCI_MSIX_PBA		8
#define  PCI_MSIX_BIR		0x7

/*
 * The PCI interface treats multi-function devices as independent
 * devices.  The slot/function address of each device is encoded
 * in a single byte as follows:
 *
 *	7:3 = slot
 *	2:0 = function
 */
#define PCI_DEVFN(slot,func)	((((slot) & 0x1f) << 3) | ((func) & 0x07))
#define PCI_SLOT(devfn)		(((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn)		((devfn) & 0x07)

/* Device classes and subclasses */

#define PCI_CLASS_NOT_DEFINED		0x0000
#define PCI_CLASS_NOT_DEFINED_VGA	0x0001

#define PCI_BASE_CLASS_STORAGE		0x01
#define PCI_CLASS_STORAGE_SCSI		0x0100
#define PCI_CLASS_STORAGE_IDE		0x0101
#define PCI_CLASS_STORAGE_FLOPPY	0x0102
#define PCI_CLASS_STORAGE_IPI		0x0103
#define PCI_CLASS_STORAGE_RAID		0x0104
#define PCI_CLASS_STORAGE_OTHER		0x0180

#define PCI_BASE_CLASS_NETWORK		0x02
#define PCI_CLASS_NETWORK_ETHERNET	0x0200
#define PCI_CLASS_NETWORK_TOKEN_RING	0x0201
#define PCI_CLASS_NETWORK_FDDI		0x0202
#define PCI_CLASS_NETWORK_ATM		0x0203
#define PCI_CLASS_NETWORK_OTHER		0x0280

#define PCI_BASE_CLASS_DISPLAY		0x03
#define PCI_CLASS_DISPLAY_VGA		0x0300
#define PCI_CLASS_DISPLAY_XGA		0x0301
#define PCI_CLASS_DISPLAY_OTHER		0x0380

#define PCI_BASE_CLASS_MULTIMEDIA	0x04
#define PCI_CLASS_MULTIMEDIA_VIDEO	0x0400
#define PCI_CLASS_MULTIMEDIA_AUDIO	0x0401
#define PCI_CLASS_MULTIMEDIA_OTHER	0x0480

#define PCI_BASE_CLASS_MEMORY		0x05
#define  PCI_CLASS_MEMORY_RAM		0x0500
#define  PCI_CLASS_MEMORY_FLASH		0x0501
#define  PCI_CLASS_MEMORY_OTHER		0x0580

#define PCI_BASE_CLASS_BRIDGE		0x06
#define  PCI_CLASS_BRIDGE_HOST		0x0600
#define  PCI_CLASS_BRIDGE_ISA		0x0601
#define  PCI_CLASS_BRIDGE_EISA		0x0602
#define  PCI_CLASS_BRIDGE_MC		0x0603
#define  PCI_CLASS_BRIDGE_PCI		0x0604
#define  PCI_CLASS_BRIDGE_PCMCIA	0x0605
#define  PCI_CLASS_BRIDGE_NUBUS		0x0606
#define  PCI_CLASS_BRIDGE_CARDBUS	0x0607
#define  PCI_CLASS_BRIDGE_OTHER		0x0680

#define PCI_BASE_CLASS_COMMUNICATION	0x07
#define PCI_CLASS_COMMUNICATION_SERIAL	0x0700
#define PCI_CLASS_COMMUNICATION_PARALLEL 0x0701
#define PCI_CLASS_COMMUNICATION_OTHER	0x0780

#define PCI_BASE_CLASS_SYSTEM		0x08
#define PCI_CLASS_SYSTEM_PIC		0x0800
#define PCI_CLASS_SYSTEM_DMA		0x0801
#define PCI_CLASS_SYSTEM_TIMER		0x0802
#define PCI_CLASS_SYSTEM_RTC		0x0803
#define PCI_CLASS_SYSTEM_OTHER		0x0880

#define PCI_BASE_CLASS_INPUT		0x09
#define PCI_CLASS_INPUT_KEYBOARD	0x0900
#define PCI_CLASS_INPUT_PEN		0x0901
#define PCI_CLASS_INPUT_MOUSE		0x0902
#define PCI_CLASS_INPUT_OTHER		0x0980

#define PCI_BASE_CLASS_DOCKING		0x0a
#define PCI_CLASS_DOCKING_GENERIC	0x0a00
#define PCI_CLASS_DOCKING_OTHER		0x0a01

#define PCI_BASE_CLASS_PROCESSOR	0x0b
#define PCI_CLASS_PROCESSOR_386		0x0b00
#define PCI_CLASS_PROCESSOR_486		0x0b01
#define PCI_CLASS_PROCESSOR_PENTIUM	0x0b02
#define PCI_CLASS_PROCESSOR_ALPHA	0x0b10
#define PCI_CLASS_PROCESSOR_POWERPC	0x0b20
#define PCI_CLASS_PROCESSOR_CO		0x0b40

#define PCI_BASE_CLASS_SERIAL		0x0c
#define PCI_CLASS_SERIAL_FIREWIRE	0x0c00
#define PCI_CLASS_SERIAL_ACCESS		0x0c01
#define PCI_CLASS_SERIAL_SSA		0x0c02
#define PCI_CLASS_SERIAL_USB		0x0c03
#define PCI_CLASS_SERIAL_FIBER		0x0c04

#define PCI_CLASS_OTHERS		0xff

/* Several ID's we need in the library */

#define PCI_VENDOR_ID_INTEL		0x8086
#define PCI_VENDOR_ID_COMPAQ		0x0e11
