Point.____Init:
	BeginFunc 0 ;
	*(this + 4) = xVal ;
	*(this + 8) = yVal ;
	EndFunc ;
Point.____PrintSelf:
	BeginFunc 20 ;
	_tmp0 = "[" ;
	PushParam _tmp0 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp1 = *(this + 4) ;
	PushParam _tmp1 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp2 = ", " ;
	PushParam _tmp2 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp3 = *(this + 8) ;
	PushParam _tmp3 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp4 = "]\n" ;
	PushParam _tmp4 ;
	LCall _PrintString ;
	PopParams 4 ;
	EndFunc ;
VTable Point =
	Point.____Init,
	Point.____PrintSelf,
; 
Rect.____Init:
	BeginFunc 344 ;
	_tmp5 = 2 ;
	_tmp6 = 4 ;
	_tmp7 = 0 ;
	_tmp8 = _tmp5 < _tmp7 ;
	_tmp9 = _tmp5 == _tmp7 ;
	_tmp10 = _tmp8 || _tmp9 ;
	IfZ _tmp10 Goto _L0 ;
	_tmp11 = "Decaf runtime error: Array size is <= 0\n" ;
	PushParam _tmp11 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L0:
	_tmp12 = _tmp5 * _tmp6 ;
	_tmp13 = _tmp6 + _tmp12 ;
	PushParam _tmp13 ;
	_tmp14 = LCall _Alloc ;
	PopParams 4 ;
	*(_tmp14) = _tmp5 ;
	*(this + 4) = _tmp14 ;
	_tmp15 = 8 ;
	_tmp16 = 4 ;
	_tmp17 = _tmp16 + _tmp15 ;
	PushParam _tmp17 ;
	_tmp18 = LCall _Alloc ;
	PopParams 4 ;
	_tmp19 = Point ;
	*(_tmp18) = _tmp19 ;
	_tmp20 = *(this + 4) ;
	_tmp21 = 0 ;
	_tmp22 = 0 ;
	_tmp23 = *(_tmp20) ;
	_tmp24 = _tmp21 < _tmp22 ;
	_tmp25 = _tmp23 < _tmp21 ;
	_tmp26 = _tmp23 == _tmp21 ;
	_tmp27 = _tmp25 || _tmp26 ;
	_tmp28 = _tmp27 || _tmp24 ;
	IfZ _tmp28 Goto _L1 ;
	_tmp29 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp29 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L1:
	_tmp30 = 4 ;
	_tmp31 = _tmp21 * _tmp30 ;
	_tmp32 = _tmp31 + _tmp30 ;
	_tmp33 = _tmp20 + _tmp32 ;
	*(_tmp33) = _tmp18 ;
	_tmp34 = *(_tmp33) ;
	PushParam y ;
	PushParam x ;
	_tmp35 = *(this + 4) ;
	_tmp36 = 0 ;
	_tmp37 = 0 ;
	_tmp38 = *(_tmp35) ;
	_tmp39 = _tmp36 < _tmp37 ;
	_tmp40 = _tmp38 < _tmp36 ;
	_tmp41 = _tmp38 == _tmp36 ;
	_tmp42 = _tmp40 || _tmp41 ;
	_tmp43 = _tmp42 || _tmp39 ;
	IfZ _tmp43 Goto _L2 ;
	_tmp44 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp44 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L2:
	_tmp45 = 4 ;
	_tmp46 = _tmp36 * _tmp45 ;
	_tmp47 = _tmp46 + _tmp45 ;
	_tmp48 = _tmp35 + _tmp47 ;
	_tmp49 = *(_tmp48) ;
	PushParam _tmp49 ;
	_tmp50 = *(_tmp49) ;
	_tmp51 = *(_tmp50) ;
	ACall _tmp51 ;
	PopParams 12 ;
	_tmp52 = 8 ;
	_tmp53 = 4 ;
	_tmp54 = _tmp53 + _tmp52 ;
	PushParam _tmp54 ;
	_tmp55 = LCall _Alloc ;
	PopParams 4 ;
	_tmp56 = Point ;
	*(_tmp55) = _tmp56 ;
	_tmp57 = *(this + 4) ;
	_tmp58 = 1 ;
	_tmp59 = 0 ;
	_tmp60 = *(_tmp57) ;
	_tmp61 = _tmp58 < _tmp59 ;
	_tmp62 = _tmp60 < _tmp58 ;
	_tmp63 = _tmp60 == _tmp58 ;
	_tmp64 = _tmp62 || _tmp63 ;
	_tmp65 = _tmp64 || _tmp61 ;
	IfZ _tmp65 Goto _L3 ;
	_tmp66 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp66 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L3:
	_tmp67 = 4 ;
	_tmp68 = _tmp58 * _tmp67 ;
	_tmp69 = _tmp68 + _tmp67 ;
	_tmp70 = _tmp57 + _tmp69 ;
	*(_tmp70) = _tmp55 ;
	_tmp71 = *(_tmp70) ;
	_tmp72 = x + w ;
	_tmp73 = y + h ;
	PushParam _tmp73 ;
	PushParam _tmp72 ;
	_tmp74 = *(this + 4) ;
	_tmp75 = 1 ;
	_tmp76 = 0 ;
	_tmp77 = *(_tmp74) ;
	_tmp78 = _tmp75 < _tmp76 ;
	_tmp79 = _tmp77 < _tmp75 ;
	_tmp80 = _tmp77 == _tmp75 ;
	_tmp81 = _tmp79 || _tmp80 ;
	_tmp82 = _tmp81 || _tmp78 ;
	IfZ _tmp82 Goto _L4 ;
	_tmp83 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp83 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L4:
	_tmp84 = 4 ;
	_tmp85 = _tmp75 * _tmp84 ;
	_tmp86 = _tmp85 + _tmp84 ;
	_tmp87 = _tmp74 + _tmp86 ;
	_tmp88 = *(_tmp87) ;
	PushParam _tmp88 ;
	_tmp89 = *(_tmp88) ;
	_tmp90 = *(_tmp89) ;
	ACall _tmp90 ;
	PopParams 12 ;
	EndFunc ;
Rect.____PrintSelf:
	BeginFunc 148 ;
	_tmp91 = "{\n lower left = " ;
	PushParam _tmp91 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp92 = *(this + 4) ;
	_tmp93 = 0 ;
	_tmp94 = 0 ;
	_tmp95 = *(_tmp92) ;
	_tmp96 = _tmp93 < _tmp94 ;
	_tmp97 = _tmp95 < _tmp93 ;
	_tmp98 = _tmp95 == _tmp93 ;
	_tmp99 = _tmp97 || _tmp98 ;
	_tmp100 = _tmp99 || _tmp96 ;
	IfZ _tmp100 Goto _L5 ;
	_tmp101 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp101 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L5:
	_tmp102 = 4 ;
	_tmp103 = _tmp93 * _tmp102 ;
	_tmp104 = _tmp103 + _tmp102 ;
	_tmp105 = _tmp92 + _tmp104 ;
	_tmp106 = *(_tmp105) ;
	PushParam _tmp106 ;
	_tmp107 = *(_tmp106) ;
	_tmp108 = *(_tmp107 + 4) ;
	ACall _tmp108 ;
	PopParams 4 ;
	_tmp109 = " upper right = " ;
	PushParam _tmp109 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp110 = *(this + 4) ;
	_tmp111 = 1 ;
	_tmp112 = 0 ;
	_tmp113 = *(_tmp110) ;
	_tmp114 = _tmp111 < _tmp112 ;
	_tmp115 = _tmp113 < _tmp111 ;
	_tmp116 = _tmp113 == _tmp111 ;
	_tmp117 = _tmp115 || _tmp116 ;
	_tmp118 = _tmp117 || _tmp114 ;
	IfZ _tmp118 Goto _L6 ;
	_tmp119 = "Decaf runtime error: Array subscript out of bound..." ;
	PushParam _tmp119 ;
	LCall _PrintString ;
	PopParams 4 ;
	LCall _Halt ;
_L6:
	_tmp120 = 4 ;
	_tmp121 = _tmp111 * _tmp120 ;
	_tmp122 = _tmp121 + _tmp120 ;
	_tmp123 = _tmp110 + _tmp122 ;
	_tmp124 = *(_tmp123) ;
	PushParam _tmp124 ;
	_tmp125 = *(_tmp124) ;
	_tmp126 = *(_tmp125 + 4) ;
	ACall _tmp126 ;
	PopParams 4 ;
	_tmp127 = "}\n" ;
	PushParam _tmp127 ;
	LCall _PrintString ;
	PopParams 4 ;
	EndFunc ;
VTable Rect =
	Rect.____Init,
	Rect.____PrintSelf,
; 
main:
	BeginFunc 64 ;
	_tmp128 = 4 ;
	_tmp129 = 4 ;
	_tmp130 = _tmp129 + _tmp128 ;
	PushParam _tmp130 ;
	_tmp131 = LCall _Alloc ;
	PopParams 4 ;
	_tmp132 = Rect ;
	*(_tmp131) = _tmp132 ;
	r = _tmp131 ;
	_tmp133 = 10 ;
	_tmp134 = 10 ;
	_tmp135 = 5 ;
	_tmp136 = 28 ;
	PushParam _tmp136 ;
	PushParam _tmp135 ;
	PushParam _tmp134 ;
	PushParam _tmp133 ;
	PushParam r ;
	_tmp137 = *(r) ;
	_tmp138 = *(_tmp137) ;
	ACall _tmp138 ;
	PopParams 20 ;
	PushParam r ;
	_tmp139 = *(r) ;
	_tmp140 = *(_tmp139 + 4) ;
	ACall _tmp140 ;
	PopParams 4 ;
	EndFunc ;
