VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Socket"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Option Explicit

Private m_Handle As Long
Private m_SD As Winsock
Attribute m_SD.VB_VarHelpID = -1

Public User

Public Event OnClose()
Public Event OnConnect()
Public Event OnConnectionRequest(ByVal requestID As Long)
Public Event OnDataArrival(ByVal bytesTotal As Long)
Public Event OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
Public Event OnSendComplete()
Public Event OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)

Implements SocketEvents

Public Property Get BytesReceived() As Long
    BytesReceived = m_SD.BytesReceived
End Property

Public Property Get LocalHostName() As String
    LocalHostName = m_SD.LocalHostName
End Property

Public Property Get LocalIP() As String
    LocalIP = m_SD.LocalIP
End Property

Public Property Get LocalPort() As Long
    LocalPort = m_SD.LocalPort
End Property

Public Property Let LocalPort(ByVal newval As Long)
    m_SD.LocalPort = newval
End Property
'
'Public Property Get Object() As Object
'    Set Object = m_SD.Object
'End Property
'
'Public Property Get Parent() As Object
'    Set Parent = m_SD.Parent
'End Property

Public Property Get Protocol() As ProtocolConstants
    Protocol = m_SD.Protocol
End Property

Public Property Let Protocol(ByVal newval As ProtocolConstants)
    m_SD.Protocol = newval
End Property

Public Property Get RemoteHost() As String
    RemoteHost = m_SD.RemoteHost
End Property

Public Property Let RemoteHost(ByVal newval As String)
    m_SD.RemoteHost = newval
End Property

Public Property Get RemoteHostIP() As String
    RemoteHostIP = m_SD.RemoteHostIP
End Property

Public Property Get RemotePort() As Long
    RemotePort = m_SD.RemotePort
End Property

Public Property Let RemotePort(ByVal newval As Long)
    m_SD.RemotePort = newval
End Property

Public Property Get SocketHandle() As Long
    SocketHandle = m_SD.SocketHandle
End Property

Public Property Get State() As StateConstants
    State = m_SD.State
End Property

Public Property Get Tag() As String
    Tag = m_SD.Tag
End Property

Public Property Let Tag(ByVal newval As String)
    m_SD.Tag = newval
End Property

Public Sub Bind(Optional LocalPort As Long = DEFAULT_PORT, _
                Optional LocalIP As String)
    If IsMissing(LocalIP) Then
        m_SD.Bind LocalPort
    Else
        m_SD.Bind LocalPort, LocalIP
    End If
End Sub

Public Sub Listen(Optional ByVal LocalPort As Long = DEFAULT_PORT)
    If m_SD.LocalPort <> LocalPort Then
        m_SD.LocalPort = LocalPort
    End If
    m_SD.Listen
End Sub

Public Sub Accept(ByVal requestID As Long)
    m_SD.Accept requestID
End Sub

Public Sub Connect(Optional ByVal RemoteHost, _
                   Optional ByVal RemotePort = DEFAULT_PORT)
    m_SD.Connect RemoteHost, RemotePort
End Sub

Public Sub Close_()
    m_SD.Close
End Sub

Public Sub GetData(ByRef Data, Optional ByVal Type_, Optional ByVal MaxLen)
    m_SD.GetData Data, Type_, MaxLen
End Sub

Public Sub PeekData(ByRef Data, Optional ByVal Type_, Optional ByVal MaxLen)
    m_SD.PeekData Data, Type_, MaxLen
End Sub

Public Sub SendData(ByVal Data)
    m_SD.SendData Data
End Sub

Private Sub Class_Initialize()
    m_Handle = Resources.AllocSocket(Me)
    Set m_SD = Resources.Socket(m_Handle)
End Sub

Private Sub Class_Terminate()
    m_SD.Close
    Set m_SD = Nothing
    Resources.FreeSocket m_Handle
End Sub

Private Sub SocketEvents_OnClose()
    RaiseEvent OnClose
End Sub

Private Sub SocketEvents_OnConnect()
    RaiseEvent OnConnect
End Sub

Private Sub SocketEvents_OnConnectionRequest(ByVal requestID As Long)
    RaiseEvent OnConnectionRequest(requestID)
End Sub

Private Sub SocketEvents_OnDataArrival(ByVal bytesTotal As Long)
    RaiseEvent OnDataArrival(bytesTotal)
End Sub

Private Sub SocketEvents_OnError(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    RaiseEvent OnError(Number, Description, Scode, Source, HelpFile, HelpContext, CancelDisplay)
End Sub

Private Sub SocketEvents_OnSendComplete()
    RaiseEvent OnSendComplete
End Sub

Private Sub SocketEvents_OnSendProgress(ByVal bytesSent As Long, ByVal bytesRemaining As Long)
    RaiseEvent OnSendProgress(bytesSent, bytesRemaining)
End Sub