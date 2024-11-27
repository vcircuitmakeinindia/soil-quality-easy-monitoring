<script lang="ts">
	import globals from "$lib/globals";
	import utils from "$lib/utils";
	import { onMount } from "svelte";

	const { readings } = $props();

	let showing = $state(Array(readings.length).fill(0));
	let container = $state();
	let colors = $state(Array(readings.length).fill({}));

	const adjustCircles = () => {
		for (let circle of document.getElementsByClassName("reading-circle")) {
			circle.style.width = `${(1 / 3) * container.clientWidth}px`;
		}
	};

	const getCircleColors = () => {
		for (let i = 0; i < readings.length; i++) {
      if (showing[i] == null) showing = Array(readings.length).fill(0);
			const { low, high } = globals.COLORS[showing[i]];
			const { min, max, inverse: inv } = globals.EXTREMES[showing[i]];
			const p = utils.findP(min, max, inv, readings[i][globals.OPTIONS[showing[i]]]);
			const color = [...utils.colorP(low, high, p), globals.ALPHA];
			colors[i] = {
				fg: "white",
				bg: utils.rgbaToHex(color)
			};
		}
	};

	$effect(() => readings && (adjustCircles(), getCircleColors()));
	$effect(() => showing && getCircleColors());

	const nextReading = (i: number) => {
		if (++showing[i] >= globals.OPTIONS.length) showing[i] = 0;
	};
	const getNextReadingFunc = (i: number) => () => nextReading(i);

	onMount(() => {
		adjustCircles();
		addEventListener("resize", adjustCircles);
	});
</script>

<div id="visual-container" bind:this={container}>
	{#each readings as c, i}
		{#if colors[i] != null && showing[i] != null}
			{@const { bg, fg } = colors[i]}
			{@const opt = globals.OPTIONS[showing[i]]}
			{@const onclick = getNextReadingFunc(i)}
			<div
				class="cluster-reading"
				style:grid-column={readings.length % 2 === 1 && i === readings.length - 1 ? "span 2" : ""}
			>
				<div class="reading-circle" style:background-color={bg} {onclick}>
					<p style:color={fg}>
						Cluster {c.cluster_no}<br />
						{opt[0].toUpperCase() + opt.slice(1)}
					</p>
				</div>
			</div>
		{/if}
	{/each}
</div>

<style>
	#visual-container {
		display: grid;
		grid-template-columns: 1fr 1fr;

		background-image: url("$lib/assets/soil.png");
		background-size: cover;

		font-family: "Parkinsans", sans-serif;
	}

	.cluster-reading {
		display: flex;
		align-items: center;
		justify-content: center;
	}

	.reading-circle {
		display: flex;
		align-items: center;
		justify-content: center;

		aspect-ratio: 1;

		border-radius: 50%;

		cursor: pointer;
	}

	.reading-circle > p {
		text-align: center;
		text-shadow:
			-1px -1px 0 #000,
			1px -1px 0 #000,
			-1px 1px 0 #000,
			1px 1px 0 #000;
		user-select: none;
	}
</style>
