#pragma once
class Validator
{
private:
	bool VIs_valid;
public:
	bool check_col_and_row(int arr[][9]);

	struct Points
	{
		float x, y;
	};
};

