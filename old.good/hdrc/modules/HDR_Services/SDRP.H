

#pragma once


/*
    SDR Procedure
    ---------------------------------------------------------------------------

        P - User Interface Parameters
        K - Kernel Function Factor Values
        R - Analyse Report
*/

struct BrokenInfo {
    enum BrokenCourseType {
        cuzPhysical,                    // һ������ԭ��
        cuzPhysicalFall,                // ˤ��
        cuzPhysicalShake,               // �񶯹���
        cuzPhysicalShock,               // ǿ�������
        cuzPhysicalUpsideDown,          // ����ʱ���û�ֱ����
        cuzPhysicalEnvironment,         // ��ʪ�ȳ���ָ���
        cuzVirus,                       // �������ƻ�
        cuzToolsForFormat,              // ʹ���˸�ʽ������
        cuzToolsForPartition,           // ʹ���˷�������, ��fdisk, pqmagic, 
        cuzToolsForRecover,             // ʹ���˻ָ�����, ��KV300�������ָ�, RecoverNTFS�ļ��ָ�, CHKDSK��ʧ�ػָ���
        cuzToolsForLowCopy,             // ʹ���˵ͼ���������, ��HDCOPY, Norton Ghost
        cuzExpired,                     // �����˿ɿ�ʹ�õ�����
        cuzAbnormalShutdown,            // �������ػ�
    }; 

    enum BrokenBehaviorType {
        beDiskNotFound,                 // ��·���ͷ�ȹ���, BIOS��֧��, ���Դ/������δ����
        beDiskNotMount,                 // MBR��
        bePartNotFound,                 // MBR����չ������¼�ж�ʧ�÷�����Ϣ, ��������ļ�ϵͳ�޷�ʶ��
        bePartNotMount,                 // ����BPB��, ���Ŀ¼δ�ҵ�, ����ϵͳ�����ϸ�Ŀ¼��Ч��
        bePartNotBootUp,                // �ǻ����, ����ϵͳ�ļ���ʧ��
        beDirectoryClobber,             // Ŀ¼����, (����Ŀ¼������Ŀ¼)
        beDataError,                    // ���ݴ���
        beDataInstability,              // ���ݲ��ȶ�
        beIOLatency,                    // I/O ��ʱ
    }; 

    // ��ز���
    enum BrokenBehaviorValues {
        DC_Root,                        // ��Ŀ¼����
        DC_Other,                       // ����Ŀ¼����(����Ŀ¼, ��ֹһ����)
        DE_LotsOfLostClusters,          // ���ݴ��� - ���ִ�����ʧ��
        DE_Recently,                    // ���ݴ��� - ���
        DE_Ago,                         // ���ݴ��� - ��ǰ
        DI_LotsOfBadSectors,            // ���ݲ��ȶ� - ��������
        DI_OldFiles,                    // ���ݲ��ȶ� - �ر������ڵ��ļ������޹ʳ���
        IOL_Aware,                      // I/O ��ʱ - �ɲ����
        IOL_Anxious,                    // I/O ��ʱ - ���ظ��ŵ�
    }; 

    BrokenCourseType        m_Course; 
    BrokenBehaviorType      m_Behavior; 
    BrokenBehaviorValues    m_Detail; 
}; 


// P0 - Overview Analyse

    // Disk rather than Partition
    struct Disk_P0 {
    }; 

    struct FATx_P0 {
        struct Parameters {
            BOOL bDetectClusterSize;                // �ֽڵ�λ
            BOOL bDetectFATxSubSystem;              // FAT-12, FAT-16, FAT-32 ֮һ
            BOOL bDetectFATMirroring; 
            BOOL bDetectActiveFAT;                  // ��һ��FAT�����ǻ��
            BOOL bDetectFSI;                        // ʶ�� FSI
            BOOL bDetectBootBackup;                 // ʶ�� BPB ����
        } P; 
        struct Kernel {
        } K; 
        struct Report {
        } R; 
    }; 


// P1 - Structured Analyse

    struct FATx_P1 {
        struct Parameters {
            BOOL bDetectRootCluster;                // ��Ŀ¼���ڴ�
            BOOL bDetectRootSize;                   // ��Ŀ¼������ļ���
        } P; 
        struct Kernel {
        } K; 
        struct Report {
        } R; 
    }; 

// P2 - Review & Dump


    struct FATx_P2 {
        struct Parameters {
        } P; 
        struct Kernel {
        } K; 
        struct Report {
        } R; 
    }; 


// SDR Procedures

    struct FATx_SDRP {
        FATx_P0 P0; 
        FATx_P1 P1; 
        FATx_P2 P2; 
    }; 


    struct ServiceFeatures {
        BOOL    FileAccessSupport; 
        //BOOL    
    }; 


    struct IFSAccess {
        ILockByts *Open(ID); 
    }; 