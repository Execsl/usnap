VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Connection"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Socket As Winsock
Private m_Name As String
Private m_Key As KeyExchange

Public Sub SetName(ByVal NewName As String)
    m_Name = NewName
    
End Sub

Public Sub SetKey(ByVal k As KeyExchange)
    Set m_Key = k
End Sub