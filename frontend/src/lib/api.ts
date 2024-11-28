import globals from "./globals";

const ENDPOINT = "http://localhost:5000/sqm"; // update endpoint to fetch from api

export async function getData() {
  // return genMockData(); // comment this line to fetch from api
	const resp = await fetch(ENDPOINT);
	if (resp.status !== 200) return genMockData();
	try {
		return await resp.json();
	} catch {
		return genMockData();
	}
}

export function genMockData(len: number = 3) {
	const readings = Array(len);
	for (let i = 0; i < readings.length; i++) {
		readings[i] = { humidity: 0, temperature: 0, moisture: 0 };
		for (let key of Object.keys(readings[i])) {
			const { min, max } = globals.EXTREMES[globals.OPTIONS.indexOf(key)];
			readings[i][key] = Math.round(Math.random() * (max - min) + min);
		}
		readings[i].cluster_no = i + 1;
	}
	return readings;
}

export default {
	getData
};
