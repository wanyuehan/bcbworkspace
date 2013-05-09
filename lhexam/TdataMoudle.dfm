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
    object RSFHX1: TBCDField
      FieldName = 'Flh1'
      DisplayFormat = '0.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFHX2: TBCDField
      FieldName = 'Flh2'
      DisplayFormat = '0.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
    end
    object RSFHX: TBCDField
      FieldName = 'Flh'
      DisplayFormat = '0.00'
      EditFormat = '00.00'
      MaxValue = 10.000000000000000000
      Precision = 18
      Size = 2
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
    object RSFLHFLAG: TSmallintField
      FieldName = 'FLHFLAG'
    end
  end
end
