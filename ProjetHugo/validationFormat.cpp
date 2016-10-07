/*
 * validationFormat.cpp
 *
 *  Created on: 2016-10-06
 *      Author: etudiant
 */

#include <iostream>
#include "stdafx.h"
#include "validationFormat.h"

bool validerImmatriculation (const std::string& p_immatriculation)
{
	int verifier = 0;
	if (p_immatriculation.length() != 7)
	{
		return false;
	}
	else
	{
	if (p_immatriculation[0] == 'L')
	{
		for (verifier = 0; verifier < 7; verifier++)
		{
		if (isdigit(verifier))
		{

		} else
		{
			return false;
		}
		} return true;
	} else
	{
		if (isupper(p_immatriculation[0]))
		{
			if (isupper(p_immatriculation[1]))
			{
				if (isupper(p_immatriculation[2]))
				{
					if (p_immatriculation[3] == ' ')
					{
						int verifier = 4;
						for (verifier = 4; verifier < 7; verifier++)
						{
							if (isdigit(p_immatriculation[2]))
							{

							} else
							{
								return false;
							}
						} return true;
					}else
					{

					}
				}else
				{
					return false;
				}
			} else
				{
					if (isdigit(p_immatriculation[1]))
					{
						if (isdigit(p_immatriculation[2]))
						{
							if (p_immatriculation[3] == ' ')
							{
								int verifier = 4;
								for (verifier = 4; verifier < 7; verifier++)
								{
									if (isupper(p_immatriculation[verifier]))
									{

									} else
									{
										return false;
									}
								} return true;
							}else
							{
								return false;
							}
						}
					} return false;
				}

		} else
		{
			int verifier = 0;
			for (verifier = 0; verifier < 3; verifier++)
			{
				if (isdigit(p_immatriculation[verifier]))
				{

				}else
				{
					return false;
				}
			}
			if (p_immatriculation[3] == 'H')
			{
				int verifier = 4;
				for (verifier = 4; verifier < 7; verifier++)
				{
					if (isdigit(p_immatriculation[verifier]))
					{

					} else
						{
						return false;
						}
				} return true;
			} else
			{
				if (p_immatriculation[3] == ' ')
				{
					int verifier = 4;
					for (verifier = 4; verifier < 7; verifier++)
					{
						if (isupper(p_immatriculation[verifier]))
						{

						} else
							{
							return false;
							}
					} return true;
				} else
				{
					return false;
				}
			}
		}
	}
}
}

bool validerNiv (const std::string& p_niv)
{
	int longueur = 0;
	int multiplicateur = 0;
	int totaux [17];
	int poids [17] = {8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2};
	int checkdigit = 0;
	int valnum[17];

	longueur = p_niv.length();
if 	(p_niv[9] == 'X')
{
	checkdigit = 10;
} else
{
	if (isdigit(p_niv[9]))
	{
		checkdigit = p_niv[9];
	}else
	{
		return false;
	}
}
	if (longueur != 17)
	{
		return false;
	} else
	{
		int verifier = 0;
		for (verifier = 0; verifier < 17; verifier++)
		{
			if (isdigit(p_niv[verifier]))
			{
				valnum[verifier] = p_niv[verifier];
			} else
				{
					if (p_niv[verifier] == 'A' ||
						p_niv[verifier] == 'J')
					{
						valnum[verifier] = 1;
					} else
					{
						if (p_niv[verifier] == 'B' ||
							p_niv[verifier] == 'K' ||
							p_niv[verifier] == 'S')
						{
							valnum[verifier] = 2;
						} else
						{
							if (p_niv[verifier] == 'C' ||
								p_niv[verifier] == 'L' ||
								p_niv[verifier] == 'T')
							{
								valnum[verifier] = 3;
							}else
							{
								if (p_niv[verifier] == 'D' ||
									p_niv[verifier] == 'M' ||
									p_niv[verifier] == 'U')
								{
									valnum[verifier] = 4;
								}else
								{
									if (p_niv[verifier] == 'E' ||
										p_niv[verifier] == 'N' ||
										p_niv[verifier] == 'V')
									{
										valnum[verifier] = 5;
									}else
									{
										if (p_niv[verifier] == 'F' ||
											p_niv[verifier] == 'W')
										{
											valnum[verifier] = 6;
										}else
										{
											if (p_niv[verifier] == 'G' ||
												p_niv[verifier] == 'P' ||
												p_niv[verifier] == 'X')
											{
												valnum[verifier] = 7;
											}else
											{
												if (p_niv[verifier] == 'H' ||
													p_niv[verifier] == 'Y')
												{
													valnum[verifier] = 8;
												}else
												{
													if (p_niv[verifier] == 'R' ||
														p_niv[verifier] == 'Z')
													{
														valnum[verifier] = 9;
													}else
													{
														return false;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
		}
		for (multiplicateur = 0; multiplicateur < 17; multiplicateur++)
		{
			totaux [multiplicateur] = valnum[multiplicateur] * poids[multiplicateur];
		}
		int totalfinal = 0;
		int addition = 0;
		for (addition = 0; addition < 17; addition++)
		{
			totalfinal += totaux[addition];
		}
		int verificateur = totalfinal % 11;
		if (verificateur == checkdigit)
		{
			return true;
		}else
		{
			return false;
		}
	}
}
