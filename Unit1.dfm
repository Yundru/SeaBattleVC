object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 313
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  TextHeight = 15
  object Button1: TButton
    Left = 32
    Top = 128
    Width = 89
    Height = 57
    Caption = 'Play (pl1/pl2)'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 128
    Width = 89
    Height = 57
    Caption = 'Statistic'
    TabOrder = 1
  end
  object Button3: TButton
    Left = 128
    Top = 40
    Width = 89
    Height = 57
    Caption = #1082#1086#1088#1072#1073#1083#1080#1082#1080
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 32
    Top = 216
    Width = 89
    Height = 57
    Caption = 'Play (robot)'
    TabOrder = 3
    OnClick = Button4Click
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 144
    object file1: TMenuItem
      Caption = 'file'
      object N1: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      end
      object N2: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      end
    end
    object help1: TMenuItem
      Caption = 'help'
      object help2: TMenuItem
        Caption = #1057#1087#1088#1072#1074#1082#1072
        OnClick = help2Click
      end
    end
  end
end
