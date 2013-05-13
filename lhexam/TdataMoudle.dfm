object dm: Tdm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 106
  Width = 199
  object GRIDDS: TDataSource
    DataSet = RS
    Left = 8
    Top = 8
  end
  object QRY: TADOQuery
    Connection = conn
    Parameters = <>
    Left = 128
    Top = 8
  end
  object conn: TADOConnection
    Connected = True
    ConnectionString = 'FILE NAME=.\connection.udl'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'SQLOLEDB.1'
    Left = 48
    Top = 8
  end
  object RS: TADOTable
    Connection = conn
    CursorType = ctStatic
    LockType = ltBatchOptimistic
    EnableBCD = False
    IndexFieldNames = 'flhjsh'
    TableName = 'lhresault'
    Left = 88
    Top = 8
    object RSFZKH: TWideStringField
      FieldName = 'FZKH'
      Size = 12
    end
    object RSFXM: TWideStringField
      FieldName = 'FXM'
      Size = 8
    end
    object RSFLHJSH: TWideStringField
      FieldName = 'FLHJSH'
      Size = 14
    end
    object RSFWL1: TFloatField
      FieldName = 'FWL1'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSFWL2: TFloatField
      FieldName = 'FWL2'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSFWL: TFloatField
      FieldName = 'FWL'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSFHX1: TFloatField
      FieldName = 'FHX1'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSFHX2: TFloatField
      FieldName = 'FHX2'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSFHX: TFloatField
      FieldName = 'FHX'
      DisplayFormat = '0.00'
      EditFormat = '0.00'
      MaxValue = 9.990000000000000000
    end
    object RSflag: TSmallintField
      FieldName = 'flag'
    end
    object RSkddm: TStringField
      FieldName = 'kddm'
      FixedChar = True
      Size = 4
    end
    object RSkcdm: TStringField
      FieldName = 'kcdm'
      FixedChar = True
      Size = 2
    end
    object RSzwh: TStringField
      FieldName = 'zwh'
      FixedChar = True
      Size = 2
    end
  end
  object CHKDS: TDataSource
    DataSet = CHKRS
    Left = 16
    Top = 56
  end
  object CHKRS: TADOTable
    Active = True
    Connection = conn
    CursorType = ctStatic
    IndexFieldNames = 'flhjsh'
    TableName = 'lhresault'
    Left = 64
    Top = 56
    object CHKRSFZKH: TWideStringField
      FieldName = 'FZKH'
      Size = 12
    end
    object CHKRSFXM: TWideStringField
      FieldName = 'FXM'
      Size = 8
    end
    object CHKRSFLHJSH: TWideStringField
      FieldName = 'FLHJSH'
      Size = 14
    end
    object CHKRSFWL1: TBCDField
      FieldName = 'FWL1'
      Precision = 18
      Size = 2
    end
    object CHKRSFWL2: TBCDField
      FieldName = 'FWL2'
      Precision = 18
      Size = 2
    end
    object CHKRSFWL: TBCDField
      FieldName = 'FWL'
      Precision = 18
      Size = 2
    end
    object CHKRSFHX1: TBCDField
      FieldName = 'FHX1'
      Precision = 18
      Size = 2
    end
    object CHKRSFHX2: TBCDField
      FieldName = 'FHX2'
      Precision = 18
      Size = 2
    end
    object CHKRSFHX: TFMTBCDField
      FieldName = 'FHX'
      Precision = 18
      Size = 12
    end
    object CHKRSflag: TSmallintField
      FieldName = 'flag'
    end
    object CHKRSkddm: TStringField
      FieldName = 'kddm'
      FixedChar = True
      Size = 4
    end
    object CHKRSkcdm: TStringField
      FieldName = 'kcdm'
      FixedChar = True
      Size = 2
    end
    object CHKRSzwh: TStringField
      FieldName = 'zwh'
      FixedChar = True
      Size = 2
    end
  end
end
