object dm: Tdm
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Height = 85
  Width = 174
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
    ConnectionString = 'FILE NAME=.\connection.udl'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = '.\connection.udl'
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
end
